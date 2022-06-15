from unittest import TestCase
from Placar import Placar


class TestPlacar(TestCase):

    placar = None

    @classmethod
    def setUp(cls):
        cls.placar = Placar()

    @classmethod
    def tearDown(cls):
        cls.placar = None

    def test_create_placar(self):
        self.assertEqual(0, self.placar.getScore())

    def test_invalid_position(self):
        with self.assertRaises(IndexError):
            self.placar.add(0, [1, 1, 1, 1, 1])
        with self.assertRaises(IndexError):
            self.placar.add(11, [1, 1, 1, 1, 1])

    def test_occupied_position(self):
        with self.assertRaises(ValueError):
            self.placar.add(1, [1, 1, 1, 1, 1])
            self.placar.add(1, [1, 1, 1, 1, 1])

    def test_add(self):
        positions = [1, 2, 3, 4, 5, 6]
        values = [[1, 2, 3, 4, 5], [2, 3, 4, 5, 6]]
        last_score = 0

        # Test each if branch case for the add function, from positions 1 to 10
        for i in range(6):
            shift = i // 5
            self.placar.add(positions[i], values[shift])
            self.assertEqual(values[shift][i - shift], self.placar.getScore() - last_score)
            last_score = self.placar.getScore()

        self.placar.add(7, [1, 1, 2, 2, 2])
        self.assertEqual(36, self.placar.getScore())
        self.placar.add(8, [1, 2, 3, 4, 5])
        self.assertEqual(56, self.placar.getScore())
        self.placar.add(9, [1, 1, 1, 1, 2])
        self.assertEqual(86, self.placar.getScore())
        self.placar.add(10, [1, 1, 1, 1, 1])
        self.assertEqual(126, self.placar.getScore())

    def test_get_name(self):
        actual_names = ["Ones", "Twos", "Threes", "Fours", "Fives",
                        "Sixes", "Full", "Sequence", "Four of a kind", "General"]

        # getName function should return the names of each position score, in
        # increasing order
        for idx, name in enumerate(actual_names):
            self.assertIn(name, self.placar.getName(idx))

    def test_get_taken(self):
        self.partial_game(self.placar)

        taken = [1, 3, 6, 7]

        # Test if getTaken function currently accounted for mockup game positions intake
        for value in taken:
            self.assertEqual(True, self.placar.getTaken(value - 1))
        for value in range(1, 10):
            if value not in taken:
                self.assertEqual(False, self.placar.getTaken(value - 1))

    def test_conta(self):
        # Tests the static element count function, with arbitrary values
        self.assertEqual(3, Placar.conta(4, [1, 2, 3, 444, 4, 1, 4, 4, 5, 6]))
        self.assertEqual(0, Placar.conta(4, []))

    def test_check_full(self):

        self.assertEqual(True, Placar.checkFull([3, 3, 3, 4, 4]))
        self.assertEqual(True, Placar.checkFull([3, 4, 3, 4, 3]))

        # Verify each branch possibility within the checkFull function
        invalid_full_hands = [
            [1, 2, 2, 3, 3],
            [1, 1, 2, 3, 3],
            [1, 1, 1, 2, 3],
            [1, 1, 2, 2, 3],
            [1, 1, 2, 3, 3],
            [1, 2, 3, 3, 3]
        ]

        for invalid in invalid_full_hands:
            self.assertEqual(False, Placar.checkFull(invalid))

    def test_check_seq_maior(self):
        self.assertEqual(True, Placar.checkSeqMaior([1, 2, 3, 4, 5]))
        self.assertEqual(True, Placar.checkSeqMaior([6, 4, 5, 3, 2]))

        # Verify each branch possibility within the checkSeqMaior function
        invalid_full_hands = [
            [1, 1, 1, 1, 1],
            [1, 2, 2, 2, 2],
            [1, 2, 3, 3, 3],
            [1, 2, 3, 4, 4],
            [2, 2, 2, 2, 2],
            [2, 3, 3, 3, 3],
            [2, 3, 4, 4, 4],
            [2, 3, 4, 5, 5]
        ]

        for invalid in invalid_full_hands:
            self.assertEqual(False, Placar.checkSeqMaior(invalid))

    def test_check_quadra(self):
        self.assertEqual(True, Placar.checkQuadra([1, 1, 1, 1, 5]))
        self.assertEqual(True, Placar.checkQuadra([6, 1, 6, 6, 6]))

        # Verify each branch possibility within the checkQuadra function
        invalid_full_hands = [
            [1, 2, 2, 2, 3],
            [1, 1, 2, 2, 2],
            [1, 1, 1, 2, 3],
            [1, 2, 3, 3, 3],
            [1, 2, 2, 3, 3],
        ]

        for invalid in invalid_full_hands:
            self.assertEqual(False, Placar.checkQuadra(invalid))

    def test_check_quina(self):
        self.assertEqual(True, Placar.checkQuina([1, 1, 1, 1, 1]))
        self.assertEqual(True, Placar.checkQuina([6, 6, 6, 6, 6]))

        # Verify each branch possibility within the checkQuina function
        invalid_full_hands = [
            [1, 2, 2, 2, 2],
            [1, 1, 2, 2, 2],
            [1, 1, 1, 2, 2],
            [1, 1, 1, 1, 2]
        ]

        for invalid in invalid_full_hands:
            self.assertEqual(False, Placar.checkQuina(invalid))

    @staticmethod
    def partial_game(placar):
        # Generates a mockup game with current score equal to 41
        # To be used within other functions that don't necessarily want to
        # create a specific game score, but test an overall feature
        placar.add(7, [1, 1, 3, 3, 3])
        placar.add(3, [1, 3, 5, 3, 3])
        placar.add(6, [6, 6, 5, 1, 2])
        placar.add(1, [1, 1, 1, 1, 1])

    def test_get_score(self):
        # Test if the getScore function works for both a specific place
        # and the overall game score
        self.partial_game(self.placar)
        self.assertEqual(15, self.placar.getScore(6))
        self.assertEqual(41, self.placar.getScore())

    def testToString(self):
        self.partial_game(self.placar)
        expected = (
            " 5     |    15    |  (4) \n"
            "-------|----------|-------\n"
            "(2)    |   (8)    |  (5) \n"
            "-------|----------|-------\n"
            " 9     |   (9)    |   12 \n"
            "-------|----------|-------\n"
            "       |   (10)   |\n"
            "       +----------+\n"
        )
        self.assertEqual(expected, self.placar.__str__())

        self.placar.add(10, [2, 2, 2, 2, 2])
        expected = (
            " 5     |    15    |  (4) \n"
            "-------|----------|-------\n"
            "(2)    |   (8)    |  (5) \n"
            "-------|----------|-------\n"
            " 9     |   (9)    |   12 \n"
            "-------|----------|-------\n"
            "       |    40    |\n"
            "       +----------+\n"
        )
        self.assertEqual(expected, self.placar.__str__())
