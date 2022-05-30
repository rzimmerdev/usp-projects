from typing import List, Union

from products import Product, CD, DVD, Book


class Store:
    def __init__(self):
        self._stash = list()

    def get_stash(self):
        return self._stash

    @staticmethod
    def find_product(stash, barcode=None, product_name=None) -> Product:
        if barcode:
            return next((product for product in stash if product.get_barcode() == barcode), None)
        else:
            return next((product for product in stash if product.name == product_name), None)

    def adquire_product(self, product: Union[List, Product]):
        if type(product) == list:
            self._stash.extend(product)
        else:
            self._stash.append(product)

    def sell_product(self, barcode: str = None, name: str = None, quantity=1):
        if barcode:
            self.find_product(self._stash, barcode=barcode).sell(quantity)
        else:
            self.find_product(self._stash, product_name=name).sell(quantity)

    def restock_product(self, barcode: str = None, name: str = None, quantity=1):
        if barcode:
            self.find_product(self._stash, barcode=barcode).restock(quantity)
        else:
            self.find_product(self._stash, product_name=name).restock(quantity)

    def get_barcode(self, name: str):
        return self.find_product(self._stash, product_name=name).get_barcode()

    def count_stash(self):
        return {"CD": sum(x.get_total() for x in self._stash if isinstance(x, CD)),
                "DVD": sum(x.get_total() for x in self._stash if isinstance(x, DVD)),
                "Book": sum(x.get_total() for x in self._stash if isinstance(x, Book))
        }
