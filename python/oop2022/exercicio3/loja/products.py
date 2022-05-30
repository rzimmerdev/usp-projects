from abc import ABC


class Product(ABC):
    _barcode: str = "#"
    _quantity: int = 0

    name: str = ""

    def __init__(self, barcode, quantity, name):
        self._barcode = barcode
        self._quantity = quantity
        self.name = name

    def get_total(self):
        return self._quantity

    def get_barcode(self):
        return self._barcode

    def sell(self, total: 1):
        self._quantity -= total

    def restock(self, total: 1):
        self._quantity += total


class CD(Product):

    _types = ["CD-ROM", "Audio", "CD-MIDI"]

    def __init__(self, barcode, quantity, name, producer):
        super().__init__(barcode, quantity, name)

        self.type = self._types[0]
        self.producer = producer

    def get_types(self):
        return self._types


class DVD(Product):

    _types = ["DVD-RW", "DVD-RAM", "BlueRay"]

    def __init__(self, barcode, quantity, name, producer):
        super().__init__(barcode, quantity, name)

        self.type = self._types[0]
        self.producer = producer

    def get_types(self):
        return self._types


class Book(Product):
    _types = ["History", "School", "Scholar", "Journal"]

    def __init__(self, barcode: str, quantity: int, name: str, writer):
        super().__init__(barcode, quantity, name)

        self.type = self._types[0]
        self.writer = writer

    def get_types(self):
        return self._types

