from typing import List

from player import Player
from card import Card


class Main:
    @staticmethod
    def convert_indexes(parameters: str) -> List[int]:
        """
        Creates a list with each valid integer in string, separated by spaces.
        :param parameters: String from which to take indexes from.
        :return: List of integers with valid converted integers.
        """
        return [int(x) if x.isdigit() else -1 for x in parameters.split()]

    @staticmethod
    def read_bet(maximum_bet: float) -> float:
        """
        Function to keep on trying to read an integer value between allowed maximum_bet range and negative values.
        :param maximum_bet: Maximum value to allow user to bet on
        :return: Float read from console corresponding to desired bet.
        """
        while True:
            try:
                bet = float(input())
                if bet > maximum_bet or bet < 0:
                    raise ValueError
                break
            except ValueError:
                print("Valor invalido, tente novamente (Aposta maxima: {})".format(maximum_bet))

        return bet


def main():
    original_deck = list(range(52))
    player = Player(original_deck, hand_size=5)

    deck = list(set(original_deck) - set(card.__int__() for card in player.get_hand()))

    # Running game loop up until player has no cash left or decided to quit.
    while True:
        # Start with printing current cash and requiring a bet value.
        print(f"Saldo atual: R$ {player.score:.2f}")
        print("Digite sua aposta ou '0' para terminar:", end=" ")
        bet = Main.read_bet(maximum_bet=player.score)

        # If player decided not to bet, leave game loop.
        if bet == 0:
            print(f"Saldo final: R$ {player.score:.2f}!")
            break

        player.score -= bet
        deck = player.roll_hand(deck)
        player.print_hand()

        # Give player two chances to reroll hand, or keep with given cards.
        print("Insira que cartas deseja trocar separadas por espaço, ou 0 para nenhuma: ")
        deck = player.roll_hand(deck, Main.convert_indexes(input()))
        player.print_hand()
        print("Insira que cartas deseja trocar separadas por espaço, ou 0 para nenhuma: ")
        deck = player.roll_hand(deck, Main.convert_indexes(input()))
        player.print_hand()

        # Calculate resulting profit by multiplying chosen bet by last hand score multiplier.
        profit = Card.sequence_score_multiplier(player.get_hand()) * bet

        if profit:
            print(f"Parabéns, você ganhou R$ {profit:.2f}!")
            player.score += profit
        if player.score == 0:
            print("Seu saldo acabou! Game over")
            break


if __name__ == "__main__":
    main()
