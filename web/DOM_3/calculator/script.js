let result = document.getElementById('result');

function addToResult(char) {
    result.value += char;
}

function clearResult() {
    result.value = '';
}

function getResult() {
    let expression = result.value;
    let answer = eval(expression);
    result.value = answer;
}