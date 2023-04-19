let main_paragraph = document.getElementsByTagName("p")[0];
let main_title = document.getElementsByTagName("h1")[0];

let link = document.createElement("a");
link.setAttribute("href", window.location.href);
link.setAttribute("style", "font-weight: bold; text-decoration: none;");
link.innerText = "Home";
document.body.insertBefore(link, main_paragraph.nextSibling);

let words = main_paragraph.innerText.split(" ");
let count = document.createElement("a");
count.innerText = words.length.toString();
document.body.insertBefore(count, main_title);

document.head.innerHTML += '<style>.pink{color: hotpink} .purple{color: purple} .blue{color: dodgerblue}</style>';

for (let i = 0; i < words.length; i++) {
    let word = words[i];
    let length = word.replace(/\s+/g, '').length;
    if (length >= 8)
        words[i] = "<span class='pink'>" + word + "</span>";
    else if (length === 6)
        words[i] = "<span class='purple'>" + word + "</span>";
    else if (length === 4 || length === 5) {
        words[i] = "<span class='blue'>" + word + "</span>";
    }
}

const strings = words.join(" ").split(". ");
main_paragraph.innerHTML = strings.join(".<br>");