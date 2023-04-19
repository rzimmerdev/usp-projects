class Adivinha():
    def __init__(self, maximum):
        self.maximum = maximum
        self.minimum = 0
        self.current_guess = int(maximum / 2)

    def set_next_guess(self, response):
        if response == -1:
            self.current_guess = int((self.minimum + self.current_guess) / 2)
        else:
            self.current_guess = int((self.current_guess + self.maximum) / 2)

    def limit_range(self, response):
        if response == -1:
            self.maximum = self.current_guess
        if response == 1:
            self.minimum = self.current_guess


def read_int(name):
    while True:
        try:
            value = int(input("Insira {}:\n".format(name)))
            return value
        except ValueError:
            print("Valor invalido inserido, tente novamente:")


def main():

    adivinhador = Adivinha(read_int("o valor maximo para adivinhar"))

    response = read_int("-1 se for menor, 0 se for correto, e 1 se for maior: {}".format(adivinhador.current_guess))

    if response == 0:
        print(f"O número foi descoberto: {adivinhador.current_guess}")

    while response != 0:

        adivinhador.limit_range(response)
        adivinhador.set_next_guess(response)

        diff = adivinhador.maximum - adivinhador.current_guess
        if diff == -1 or diff == 1:
            print(f"Seu numero é {adivinhador.current_guess}")
            response = 0
        else:
            response = read_int("-1 se for menor, 0 se for correto, e 1 se for maior: {}".
                                format(adivinhador.current_guess))
            if response == 0:
                print(f"O número foi descoberto: {adivinhador.current_guess}")


if __name__ == "__main__":
    main()
