def read_int(name):
    while True:
        try:
            value = int(input("Insira o valor {}:\n".format(name)))
            return value
        except ValueError:
            print("Valor invalido inserido, tente novamente:")


def sqrt(x_0, error):
    guess = x_0 / 2

    while True:
        prev_guess = guess
        guess = (guess + x_0 / guess) / 2

        if abs(guess - prev_guess) < error:
            break

    return guess


def verify_primality(x):
    error = 0.00000001

    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    for i in range(3, int(sqrt(x, error)) + 1):
        if x % i == 0:
            return False
    return True


def main():
    x = read_int("do numero para verificar primalidade")

    print(f"{x} é primo.") if verify_primality(x) else print(f"{x} não é primo.")


if __name__ == "__main__":
    main()
