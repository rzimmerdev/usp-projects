from typing import List
from random import shuffle


class Card:
    """ Class to instantiate one poker card object, storing a value, a random generator for its value and a string
    representation override.
    """

    def __init__(self, maximum: int = 52):
        self._maximum = maximum - 1
        self._value = -1

    def roll(self, available: List[int] = None) -> int:
        """ Randomly sets card value from given list of available values to chose from.

        :param available: List of available values to chose from. Range of values to maximum (default 52) if empty.
        :return: Chosen value for card
        """
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
        """ Representating the card as a normal playing card in ASCII, with its suit symbol and numerical value shown.

        :return: String representation in multiple lines of a playing card in ASCII.
        """
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

    @staticmethod
    def sequence_score_multiplier(cards: list) -> int:
        """ Calculates score multiplies given sequence of cards in hand.\n
            Possible scores are, as in Poker:\n
            200x: Royal Straight Flush\n
            100x: Straight Flush\n
            50x: Four of a kind\n
            20x: Full House\n
            10x: Flush\n
            5x: Straight\n
            2x: Three of a kind\n
            1x: Two pairs\n

        :param cards: List of card objects to get values from, in any order
        :return: Multiplier to be applied to bet given a poker hand
        """
        sequence = [card.get_value() for card in cards]

        symbols = [int(card / 13) for card in sequence]
        values = sorted([int(card % 13) for card in sequence])
        ascending: bool = values == list(range(values[0], values[-1] + 1))
        frequency = [0 for _ in range(13)]

        for value in values:
            frequency[value] += 1

        if symbols[0] == 8 and ascending and len(set(symbols)) == 1:
            return 200

        elif ascending and len(set(symbols)) == 1:
            return 100

        elif 4 in frequency:
            return 50

        elif 2 in frequency and 3 in frequency:
            return 20

        elif len(set(symbols)) == 1:
            return 10

        elif ascending:
            return 5

        elif 3 in frequency:
            return 2

        elif frequency.count(2) == 2:
            return 1

        return 0
