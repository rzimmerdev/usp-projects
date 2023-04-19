colors = ["Blue ", "Green", "Red", "Orange", "Violet", "Indigo"];
order = [2, 1, 4, 5, 6, 3]

indices = order.map(function(x, i) {
    return [x, colors[i]];
});

indices = indices.sort(function(a, b) {return a[0] - b[0];});

function indicator(n) {
    return ["st", "nd", "rd"][n - 1] || "th"
}

for (const [index, color] of indices) {
    console.log(`${index}${indicator(index)} choice is ${color}.`);
}