import os
from urllib.request import urlopen
from urllib.parse import urlparse, parse_qs

import fitz  # PyMuPDF
from lxml import html
from weasyprint import HTML
from tqdm import tqdm
from langdetect import detect, LangDetectException
from deep_translator import GoogleTranslator

def extract_course_links(pdf_path):
    doc = fitz.open(pdf_path)
    course_links = []
    for page in doc:
        # noinspection PyUnresolvedReferences
        links = page.get_links()
        for link in links:
            uri = link.get("uri", "")
            if "sgldis=" in uri:
                course_links.append(uri)
    return course_links

def extract_course_code(url):
    query = urlparse(url).query
    params = parse_qs(query)
    return params.get('sgldis', [None])[0]


def clean_html(url):
    raw_html = urlopen(url).read()
    doc = html.fromstring(raw_html)
    course_title = None

    for table in reversed(doc.xpath('//table')):
        text = table.text_content()

        if table.xpath('.//img[contains(@src, "BrasaoUSP.gif")]') or \
                "Júpiter - Sistema de Gestão Acadêmica" in text or \
                "Superintendência de Tecnologia da Informação/USP" in text:
            table.getparent().remove(table)
            continue

        if "Instituto de Ciências Matemáticas e de Computação" in text:
            trs = table.xpath('.//tr')
            if len(trs) >= 2:
                code_line = trs[-2].xpath('.//td//text()[contains(., "Disciplina:")]')[0]
                if not code_line:
                    continue
                code = code_line.split(" - ")[0].replace("Disciplina: ", "").strip()
                name_line = trs[-1].xpath('.//font/span/text()')[0].strip()
                course_title = f"{code} - {name_line}"

                for tr in trs:
                    tr.getparent().remove(tr)

                new_tr = html.Element("tr")
                new_td = html.Element("td")
                new_td.set("align", "center")
                new_td.text = f"Course: {course_title}"
                new_tr.append(new_td)
                table.append(new_tr)

        for keyword in ["Objetivos", "Ementa", "Conteúdo Programático"]:
            for b in table.xpath(f'.//b[contains(text(), "{keyword}")]'):
                tr = b.xpath('./ancestor::tr[1]')
                if tr:
                    tr = tr[0]
                    # Remove <pre> elements only within this tr or its immediate sibling
                    pre_tags = tr.xpath('.//pre') + tr.xpath('following-sibling::tr[1]//pre')
                    for pre in pre_tags:
                        pre.getparent().remove(pre)

        # remove requirements table
        # for table in doc.xpath('//table'):
    #     text = table.text_content().strip()
    #     if "consultar os requisitos para" in text:
    #         table.getparent().remove(table)
    #         break
        if "consultar os requisitos para" in text:
            table.getparent().remove(table)

        # update offering link
        if "consultar o oferecimento para" in text:
            link = table.xpath('.//a[contains(@href, "obterTurma")]')
            if link:
                href = link[0].get("href")
                parsed = parse_qs(urlparse(href).query)
                class_code = parsed.get("sgldis", [""])[0]
                absolute_url = f"https://uspdigital.usp.br/jupiterweb/obterTurma?sgldis={class_code}"

                link[0].text = "Additional information on the current class schedule (in Portuguese)"
                link[0].set("href", absolute_url)

    for div in doc.xpath('//div[@id="my_web_cabecalho"]'):
        div.getparent().remove(div)

    if url == "https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=SSC0160&print=true":
        course_title = "SSC0160 - Modeling and Simulation of Computational Systems"

    return html.tostring(doc, encoding="unicode"), course_title


def translate_html_tree(doc, translator=None, cache=None):
    if translator is None:
        translator = GoogleTranslator(source='auto', target='en')
    if cache is None:
        cache = {}

    def translate_text(text):
        text = text.strip()
        if not text or len(text) < 2:
            return text
        try:
            if detect(text) == "en":
                return text
        except LangDetectException:  # Possibly not text
            return text
        if text in cache:
            return cache[text]
        try:
            translated = translator.translate(text)
            cache[text] = translated
            return translated
        except Exception:
            return text

    for el in doc.iter():
        if el.text and el.text.strip():
            el.text = translate_text(el.text)
        if el.tail and el.tail.strip():
            el.tail = translate_text(el.tail)

    return doc, cache


def download_course_pdfs(links, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    pdf_paths = []
    course_titles = []
    translator = GoogleTranslator(source='auto', target='en')
    translation_cache = {
    }

    for link in tqdm(links, desc="Downloading course PDFs"):
        printable_url = f"{link}&print=true"
        course_code = extract_course_code(link)
        output_path = f"{output_dir}/{course_code}.pdf"

        if not os.path.exists(output_path):
            raw_html, course_title = clean_html(printable_url)
            doc = html.fromstring(raw_html)
            translated_doc, translation_cache = translate_html_tree(doc, translator, translation_cache)
            HTML(string=html.tostring(translated_doc, encoding="unicode")).write_pdf(output_path)
        else:
            _, course_title = clean_html(printable_url)

        pdf_paths.append(output_path)
        course_titles.append((course_code, course_title))

    return pdf_paths, course_titles


def generate_index_pdf(course_titles, output_path):
    html_lines = ['<h1>Index</h1><ul>']
    for idx, (code, title) in enumerate(course_titles):
        if not title:
            continue
        html_lines.append(f'<li>{title}</li>')
    html_lines.append('</ul>')

    HTML(string='\n'.join(html_lines)).write_pdf(output_path)


def merge_pdfs(index_pdf, course_pdfs, output_path):
    merged = fitz.open()
    merged.insert_pdf(fitz.open(index_pdf))

    for pdf in course_pdfs:
        merged.insert_pdf(fitz.open(pdf))

    merged.save(output_path)
    merged.close()


if __name__ == "__main__":
    links = extract_course_links("catalog.pdf")
    pdf_paths, course_titles = download_course_pdfs(links, "output")

    index_path = "output/index.pdf"
    generate_index_pdf(course_titles, index_path)

    final_path = "output/merged_catalog.pdf"
    merge_pdfs(index_path, pdf_paths, final_path)