from figures import Circle, Square, Rectangle


def main():
    circulo = Circle(radius=2)

    quadrado = Square(length=3)

    retangulo = Rectangle(length=2, width=3)

    print("Area do Circulo: {:.2f}\nArea do Quadrado: {}\nArea do Retangulo: {}".format(
        circulo.get_area(), quadrado.get_area(), retangulo.get_area()
    ))


if __name__ == "__main__":
    main()
