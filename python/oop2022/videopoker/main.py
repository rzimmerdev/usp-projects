from poker import Player


def read_choice(parameters: str) -> list:
    return [int(x) if x.isdigit() else 0 for x in parameters.split()]


def main():

    original_deck = list(range(52))
    player = Player(original_deck, hand_size=5)

    deck = list(set(original_deck) - set(card.__int__() for card in player.get_hand()))




if __name__ == "__main__":
    main()
