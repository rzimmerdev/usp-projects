def sqrt(x_0, error):
    guess = x_0 / 2

    while True:
        prev_guess = guess
        guess = (guess + x_0 / guess) / 2

        if abs(guess - prev_guess) < error:
            break

    return guess


def read_float(name):
    while True:
        try:
            value = float(input("Insira o valor {}:\n".format(name)))
            return value
        except ValueError:
            print("Valor invalido inserido, tente novamente:")


def main():
    error = 0.00000001
    x = read_float("para obter a raiz")

    root = sqrt(x, error)

    print(f"O valor da raiz é {root}")


if __name__ == "__main__":
    main()
