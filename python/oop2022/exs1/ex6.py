def read_float():
    while True:
        try:
            value = float(input())
            return value
        except ValueError:
            print("Valor invalido inserido, tente novamente:")


def main():
    print("Insira a sequencia a seguir:\n")

    biggest = 0
    smallest = 0

    current = 0

    while True:
        current = read_float()
        if current == 0:
            break

        if current < smallest or smallest == 0:
            smallest = current
        if current > biggest or biggest == 0:
            biggest = current

    print(f"Maior numero foi: {biggest}, e menor foi {smallest}")


if __name__ == "__main__":
    main()
