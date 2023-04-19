from math import pi
from abc import ABC


class TwoDimensional(ABC):
    color: str = "Red"
    filled: bool = False

    def __init__(self, length_first, length_second):
        self._absolute_length = (length_first, length_second)

    # Since object abstract object is Two Dimensional Space with no specific form,
    # area of the figure is therefore undefined by Euclidian geometry concepts.
    def get_area(self):
        return None

    @staticmethod
    def prod(vector):
        return vector[0] * vector[1]


class Circle(TwoDimensional):
    def __init__(self, radius):
        super().__init__(radius, pi)

    def get_radius(self):
        return self._absolute_length[0]

    def get_radians(self):
        return self._absolute_length[1]

    def get_area(self):
        return self.get_radians() * self.get_radius() ** 2


class Rectangle(TwoDimensional):
    def __init__(self, length, width):
        super().__init__(length, width)

    def get_area(self):
        return self.prod(self._absolute_length)


class Square(TwoDimensional):
    def __init__(self, length):
        super().__init__(length, length)

    def get_area(self):
        return self.prod(self._absolute_length)
