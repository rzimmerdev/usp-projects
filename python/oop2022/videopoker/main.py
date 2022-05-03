import random


def read_choice(parameters: str) -> list:
    return [int(x) if x.isdigit() else 0 for x in parameters.split()]


class Card:
    def __init__(self, maximum=51):
        self._maximum = maximum
        self._value = -1

    def roll(self):
        self._value = random.randint(0, self._maximum - 1)

    def get_value(self):
        return self._value

    def __str__(self):
        default_drawing = [
            "{pos0}  {pos1}  {pos2}",
            "{pos3}  {pos3}  {pos3}",
            "{pos4}  {pos4}  {pos5}"
        ]

        special_drawing = [
            ["    {symbol}  ",
             "   ♘   ",
             "  {symbol}    "],
            ["    {symbol}  ",
             "   ♕   ",
             "  {symbol}    "],
            ["    {symbol}  ",
             "   ♔   ",
             "  {symbol}    "],
            ["    {symbol}  ",
             "    As   ",
             "  {symbol}    "],
        ]

        card = ("┌───────────┐"
                "│{value}          │"
                "│  {draw0}  │"
                "│           │"
                "│  {draw1}  │"
                "│           │"
                "│  {draw2}  │"
                "│          {value}│"
                "└──────────┘")

        if int((self._value % 13) > 7):
            return [line.format(int(self._value / 13)) for line in special_drawing[(self._value % 13) - 7]]

        return [line.format(int(self._value / 13)) for line in default_drawing[(self._value % 13) - 7]]


def player():
    pass


def main():
    a = Card()
    a.roll()
    print(a)


if __name__ == "__main__":
    main()
