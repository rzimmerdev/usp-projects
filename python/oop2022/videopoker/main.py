from poker import Player


def read_choice(parameters: str) -> list:
    return [int(x) if x.isdigit() else 0 for x in parameters.split()]


def read_bet(maximum_bet) -> int:
    while True:
        try:
            bet = int(input())
            if bet > maximum_bet:
                raise ValueError
            break
        except ValueError:
            print("Valor invalido, tente novamente (Aposta maxima: {})".format(maximum_bet))

    return bet


def main():

    original_deck = list(range(52))
    player = Player(original_deck, hand_size=5)

    deck = list(set(original_deck) - set(card.__int__() for card in player.get_hand()))

    while True:
        print("Saldo atual: {}".format(player.get_score()))
        print("Digite sua aposta ou '-1' para terminar:", end=" ")
        bet = read_bet(maximum_bet=player.get_score())

        if bet == -1:
            break

        player.print_hand()

        print("Digite quais cartas voce quer trocar, separado por espaco:", end=" ")
        read_choice(input())


if __name__ == "__main__":
    main()
