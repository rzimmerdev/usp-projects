from unittest.mock import patch
import unittest
from main import evaluate_reference


class MyTestCase(unittest.TestCase):

    @patch('builtins.input', return_value="""
        ex1.npy
        1024
        1
        1
        720
        6
        1
    """)
    def main(self):
        self.assertLess(evaluate_reference, 1600)  # add assertion here


if __name__ == '__main__':
    unittest.main()
