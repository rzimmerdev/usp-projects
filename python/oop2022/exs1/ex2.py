def sqrt(x_0, error):
    guess = x_0 / 2

    while True:
        prev_guess = guess
        guess = (guess + x_0 / guess) / 2

        if abs(guess - prev_guess) < error:
            break

    return guess


def solve_pol_2(a, b, c):
    delta = b * b - 4 * a * c

    if delta < 0:
        return None

    x_0 = (-b + sqrt(delta, 0.00000001)) / (2 * a)
    x_1 = (-b - sqrt(delta, 0.00000001)) / (2 * a)

    return x_0, x_1


def read_float(name):
    while True:
        try:
            value = float(input("Insira o valor {}:\n".format(name)))
            return value
        except ValueError:
            print("Valor invalido inserido, tente novamente:")


def main():
    a = read_float("do coeficiente de x^2")
    b = read_float("do coeficiente de x")
    c = read_float("da constante")

    roots = solve_pol_2(a, b, c)
    if roots:
        print(f"Raizes encontradas: x_0: {roots[0]}, x_1: {roots[1]}")
    else:
        print("Não há raizes reais.")


if __name__ == "__main__":
    main()
