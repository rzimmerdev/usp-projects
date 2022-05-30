from typing import List

from card import Card


class Player:
    """
    Player class to maintain track of a single poker hand and to execute card operations on multiple cards
    """
    def __init__(self, deck: List[int], hand_size: int = 5):
        """
        Instantiates player hand and available deck to choose first cards from.

        :param deck: List of integers from which cards can get their values from.
        :param hand_size: Total cards to be stored in a single list of cards (hand).
        """
        self._hand_size = hand_size
        self.score = 200
        self.hand = []

        for i in range(hand_size):
            new_card = Card()

            deck = list(set(deck) - set(card.get_value() for card in self.get_hand()))

            new_card.roll(deck)
            self.add_card(new_card)

    def add_card(self, card: Card):
        self.hand.append(card)

    def get_hand(self) -> List[Card]:
        return self.hand

    def print_hand(self):
        """
        Prints sequence of cards side by side in console, using each card string representation individually and
        appending by newline to each final line.

        :return: String representation of the player hand, same as each hand card side by side.
        """
        card_split = [card.__str__().split("\n") for card in self.hand]
        zipped = zip(*card_split)
        for i in range(len(self.hand)):
            print("      {}      ".format(i + 1), end="")
        print("")
        for lines in zipped:
            print("".join(lines))

    def roll_hand(self, deck: List[int], choice: List[int] = None):
        """
        Rerolls a given choice of cards in hand, using available cards in deck.
        :param deck: Deck to choose new cards from, as to be passed to card roll function.
        :param choice: Indexes of cards in hand to reroll.
        :return:
        """
        if not choice:
            choice = range(self._hand_size)

        for index in choice:
            if index <= 0 or index > 5:
                continue

            if len(set(deck)) == 0:
                deck = list(set(range(52)) - set(self.hand))

            self.hand[index - 1].roll(deck)
            deck = list(set(deck) - set(card.__int__() for card in self.hand))

        return deck
