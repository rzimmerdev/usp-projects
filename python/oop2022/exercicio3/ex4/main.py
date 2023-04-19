from store import Store
from products import CD, DVD, Book


def main():
    loja = Store()

    # Create list of new products from specific class to be added to store
    new_products = [
        CD("|||II||I||I|III", 3, "Thriller", "Michael Jackson"),
        DVD("|||II||I||I|III|", 93, "Os Croods", "Pixar"),
        Book("$|I|III|$", 42, "Harry Potter e a Pedra", "J. K. Rowling"),
        CD("I||I$|||", 10, "Windows XP Installer", "Microsoft")
    ]

    loja.adquire_product(new_products)

    # CD = 13
    # DVD = 93
    # Book = 42

    loja.sell_product(barcode="|||II||I||I|III|", quantity=33)

    # DVD = 93 - 33 = 60

    print(loja.find_product(loja.get_stash(), product_name="Os Croods"), "\n")
    loja.restock_product(barcode="|||II||I||I|III", quantity=16)

    # CD = 3 + 10 + 16 = 29

    for key, val in loja.count_stash().items():
        print(f"{key}: {val}")


if __name__ == "__main__":
    main()
