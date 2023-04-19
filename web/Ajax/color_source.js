get_color_promise(1);


function set_color(data) {
    document.getElementById("block").style.backgroundColor = data["color"];
    document.getElementById("color-name").innerText = data["name"];
    document.getElementById("color-code").innerText = data["color"];
}


function get_color_async(color_id = 1) {
    let id = document.getElementById("color-id").value || color_id;
    let xhr = new XMLHttpRequest();

    xhr.open("GET", "https://reqres.in/api/unkown/" + id, true);
    xhr.onload = function () {

        let res = JSON.parse(xhr.responseText)["data"];
        set_color(res);
    };
    xhr.send();
}

function get_color_promise(color_id = 1) {
    let id = document.getElementById("color-id").value || color_id;
    let xhr = new XMLHttpRequest();

    let promise = new Promise(function (resolve, reject) {
        xhr.open("GET", "https://reqres.in/api/unkown/" + id);
        xhr.onload = function() {
            if (xhr.status === 200) {
                resolve(xhr);
            } else {
                reject(Error(xhr.statusText));
            }
        };
        xhr.onerror = function() {
            reject(Error('error fetching JSON data'));
        };
        xhr.send();
    });

    promise.then(function (xhr) {
        let res = JSON.parse(xhr.responseText)["data"];
        set_color(res);
    }, function (error) {
        console.log(error);
    });
}
