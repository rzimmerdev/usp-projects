const arr1=[3, 'a', 'a', 'a', 2, 3, 'a', 3, 'a', 2, 4, 9];

let frequency = {};
let max_val = -Infinity;
let max_key = null;

for (const element of arr1) {
    if (frequency[element])
        frequency[element]++;
    else
        frequency[element] = 1;
}

for (const key of Object.keys(frequency)) {
    if (frequency[key] > max_val) {
        max_key = key;
        max_val = frequency[key];
    }
}

console.log(`${max_key} ( ${max_val} times )`)