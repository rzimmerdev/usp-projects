document.getElementById("change_heading").innerText = "Okay, sure."

let colors = document.getElementsByTagName("section")[0].children;
let random = document.createElement("div");

random.className = "random";

setInterval(set_random_color, 1000);

document.getElementsByTagName("section")[0].appendChild(random);


function set_random_color() {
    let color = Math.floor(Math.random()*16777215).toString(16);
    random.style.backgroundColor = "#" + color;
}


for (let color of colors) {
    const color_name = color.className;
    document.getElementsByClassName(color_name)[0].addEventListener("mouseenter", function() { show_color(color_name); } );
    document.getElementsByClassName(color_name)[0].addEventListener("mouseleave", function() { show_color("None!"); } );
}

function show_color(name) {
    document.getElementsByClassName("selected")[0].innerText = name;
}