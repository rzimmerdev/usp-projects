from store import Store
from products import CD, DVD, Book


def main():
    loja = Store()
    new_products = [
        CD("|||II||I||I|III", 3, "Thriller", "Michael Jackson"),
        DVD("|||II||I||I|III|", 93, "Os Croods", "Pixar"),
        Book("$|I|III|$", 42, "Harry Potter e a Pedra", "J. K. Rowling")
    ]

    loja.adquire_product(new_products)

    loja.sell_product(barcode="|||II||I||I|III|", quantity=33)
    print(loja.find_product(loja.get_stash(), product_name="Os Croods"))
    loja.restock_product(barcode="|||II||I||I|III", quantity=16)

    print(loja.count_stash())


if __name__ == "__main__":
    main()