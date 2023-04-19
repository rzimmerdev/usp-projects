document.getElementsByTagName("body")[0].style.font = "12px bold underlined";
document.getElementsByTagName("body")[0].style.fontFamily = "sans-serif";

const new_info = {
    "name": "Lex Fridman",
    "nickname": "Fridman",
    "favorites": "Artificial Intelligence Podcast, Lex Fridman Podcast, Papers",
    "hometown": "Chkalovsk"
}

const img_src = "https://upload.wikimedia.org/wikipedia/commons/5/50/Lex_Fridman_teaching_at_MIT_in_2018.png";

for (const [id, info] of Object.entries(new_info)) {
    document.getElementById(id).innerText = info;
}

img = document.createElement("img");
img.setAttribute("src", img_src);

document.body.appendChild(img);
