document.getElementById("lib-button").addEventListener("click", makeMadTalk);

function get_input(id) {
    return document.getElementById(id).value;
}

function makeMadTalk() {
    const inputs = ["noun", "adjective", "person"].map(get_input);
    let str = `${inputs[2]} is not creative, but is undoubtedly a ${inputs[1]} ${inputs[0]}.`

    let story = document.createElement("p");
    story.innerText = str;

    document.getElementById("story").appendChild(story);
}