let main_paragraph = document.getElementsByTagName("p")[0];
let main_title = document.getElementsByTagName("h1")[0];

let link = document.createElement("a");
link.setAttribute("href", window.location.href);
link.setAttribute("style", "font-weight: bold; text-decoration: none;");
link.innerText = "Home";
document.body.insertBefore(link, main_paragraph.nextSibling);
document.head.innerHTML += '<style>.pink{color: hotpink} .purple{color: purple} .blue{color: dodgerblue}</style>';

const words = main_paragraph.innerText.split(" ");
let count = document.createElement("a");
count.innerText = words.length.toString();
document.body.insertBefore(count, main_title);

const strings = words.join(" ").split(". ");
main_paragraph.innerHTML = strings.join(".<br>");

var colorful = false;


function set_colors() {

    let color_words = main_paragraph.innerHTML.split(" ");

    for (let i = 0; i < color_words.length; i++) {
        let word = color_words[i];
        let length = word.replace(/\s+/g, '').length;
        if (length >= 8)
            color_words[i] = "<span class='pink'>" + word + "</span>";
        else if (length === 6)
            color_words[i] = "<span class='purple'>" + word + "</span>";
        else if (length === 4 || length === 5) {
            color_words[i] = "<span class='blue'>" + word + "</span>";
        }
    }

    main_paragraph.innerHTML = color_words.join(" ");
}

function remove_colors() {
    const strings = words.join(" ").split(". ");
    main_paragraph.innerHTML = strings.join(".</br>");
}

function trigger_colors() {
    if (colorful)
        remove_colors();
    else
        set_colors();

    colorful = !colorful;
}

btn = document.createElement("button");
btn.setAttribute("onclick", "trigger_colors()");
btn.innerText = "Colorful"
document.body.insertBefore(btn, main_title.nextSibling);