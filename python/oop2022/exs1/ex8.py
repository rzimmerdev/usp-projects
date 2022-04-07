import math


def read_float(name):
    while True:
        try:
            value = float(input("Insira o valor {}:\n".format(name)))
            return value
        except ValueError:
            print("Valor invalido inserido, tente novamente:")


def f(x):
    return math.pow(x, 3) - math.pow(x, 2) - 13 * x + 8


def dy_dx(x):
    return 3 * math.pow(x, 2) - 2 * x - 13


def find_root(root, error):
    iteration = 0

    while True:
        y = f(root)
        root -= y / dy_dx(root)

        iteration += 1
        print(f"Iteracao atual: {iteration}, com aproximacao da raiz: {root}")

        if abs(y) <= error:
            break

    return root


def main():
    root = read_float("aproximado de alguma raiz")
    print("Raiz encontrada: {}".format(find_root(root, math.pow(10, -7))))


if __name__ == "__main__":
    main()
