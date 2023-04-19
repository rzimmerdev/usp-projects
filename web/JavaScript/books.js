let library = [
    {   author: 'Bill Gates',
        title: 'The Road Ahead',
        readingStatus: true
    },
    {   author: 'Steve Jobs',
        title: 'Walter Isaacson',
        readingStatus: true
    },
    {   author: 'Suzanne Collins',
        title:  'Mockingjay: The Final Book of The Hunger Games',
        readingStatus: false
    }];


function print_book(book) {
    console.log(`author: ${book["author"]}, \ntitle: ${book["title"]}, \nreadingStatus: ${book["readingStatus"]}`);
}


console.log("Library: \n")
for (const book of library)
    print_book(book);


library.push(
    {
        author: 'Dante Alighieri',
        title: 'Divine Comedy',
        readingStatus: true
    }
)

console.log("readingStatus == true: \n")

for (const book of library)
    if (book["readingStatus"])
        print_book(book);
