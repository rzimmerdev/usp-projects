from random import shuffle
from typing import List


class Card:

    def __init__(self, maximum=52):
        self._maximum = maximum - 1
        self._value = -1

    def roll(self, available=None):
        if available is None:
            available = list(range(self._maximum))
        shuffle(available)

        self._value = available[0]
        return self._value

    def get_value(self) -> int:
        return self._value

    def __int__(self):
        return self._value

    def __str__(self):

        card = ("┌───────────┐\n"
                "│ {value}        │\n"
                "│           │\n"
                "│     {symbol}     │\n"
                "│           │\n"
                "│         {value}│\n"
                "└───────────┘\n")

        symbols = ['♠', '♥', '♦', '♣']
        values = ['2 ', '3 ', '4 ', '5 ', '6 ', '7 ', '8 ', '9 ', '10', 'J ', 'Q ', 'K ', 'A ']

        return card.format(value=values[self._value % len(values)], symbol=symbols[int(self._value / len(values))])


class Player:

    def __init__(self, deck: list, hand_size=5):
        self._hand_size = hand_size
        self._score = 200
        self.hand = []

        for i in range(hand_size):
            new_card = Card()

            deck = list(set(deck) - set(card.get_value() for card in self.get_hand()))

            new_card.roll(deck)
            self.add_card(new_card)

    def get_hand(self) -> List[Card]:
        return self.hand

    def print_hand(self):

        card_split = [card.__str__().split("\n") for card in self.hand]
        zipped = zip(*card_split)

        for lines in zipped:
            print("".join(lines))

    def add_card(self, card):
        self.hand.append(card)

    def roll_card(self, index, deck):
        self.hand[index].roll(deck)


def sequence_score_multiplier(cards: List[Card]) -> int:
    sequence = sorted([card.get_value() for card in cards])

    symbols = [int(card / 13) for card in sequence]
    values = [int(card % 13) for card in sequence]

    follow = [value - min(values) for value in values]
    frequency = [0 for _ in range(13)]
    for value in values:
        frequency[value] += 1

    if symbols[0] == 8 and symbols[4] == 12 and len(set(symbols)) == 1:
        return 200

    elif follow[4] == 5 and len(set(symbols)) == 1:
        return 100

    elif 4 in frequency:
        return 50

    elif 2 in frequency and 3 in frequency:
        return 20

    elif len(set(symbols)) == 1 and follow[4] != 5:
        return 10

