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


def find_root(x_0, x_1, error, iteration=0):
    y_0 = f(x_0)
    y_1 = f(x_1)

    mean = (x_0 + x_1) / 2
    y_mean = f(mean)

    iteration += 1
    print("Iteracao atual: {}, com media da raiz: {}".format(iteration, mean))

    if abs(y_0) < error:
        return x_0
    if abs(y_1) < error:
        return x_1

    if y_mean < -error:
        return find_root(x_0, mean, error, iteration)
    if y_mean > error:
        return find_root(mean, x_1, error, iteration)
    return mean


def main():
    x_0, x_1 = 0, 0

    x_0, x_1 = read_float("de x_0"), read_float("de x_1")

    print("Obtendo raizes para f(x) = x^3 - x^2 - 13x + 8")
    print("Raiz encontrada: {}".format(find_root(x_0, x_1, math.pow(10, -7))))


if __name__ == "__main__":
    main()
