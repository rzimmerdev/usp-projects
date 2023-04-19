def read_int(name):
    while True:
        try:
            value = int(input("Insira o valor {}:\n".format(name)))
            return value
        except ValueError:
            print("Valor invalido inserido, tente novamente:")


def main():
    size = read_int("do tamanho da piramide")

    for x in range(size, 0, -1):
        print(" " * (size - x) + "*" * x)


if __name__ == "__main__":
    main()
