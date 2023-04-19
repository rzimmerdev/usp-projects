alert("Hello! Welcome to the first exercise.");
name = "";
do {
    name = prompt("Please, insert your full name below")
} while (!confirm("Is your name correct: " + name + "?"));

alert(name + ": " + name.replace(/\s+/g, '').length + " characters");