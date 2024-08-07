import argparse
import sys
from random import random


# import numpy as np


def erdos_renyi(n: int, p: float):
    if not 0 <= p <= 1:
        raise ValueError(f"Valor invalido p: {p}, precisa estar entre 0 e 1 inclusos.")

    if n < 0:
        raise ValueError(f"Valor invalido N: {n}, precisa ser maior que 0.")

    mat = [[0 for x in range(n)] for _ in range(n)]
    # mat = np.zeros((n, n))

    for i in range(0, n - 1):
        for j in range(i + 1, n):
            if random() < p:
                mat[i][j] = 1
                mat[j][i] = 1

    return mat


def main():
    parser = argparse.ArgumentParser(description='Prints Erdos-Renyi adjacency matrix given total nodes '
                                                 'and probability.')
    parser.add_argument('n', metavar='N', type=int,
                        help='total amount of nodes in graph')
    parser.add_argument('p', metavar='p',
                        help='probability to determine if two nodes are connected')

    args = parser.parse_args()

    try:
        total_nodes = int(args.n)
    except ValueError:
        print(f"Valor invalido para tamanho da matriz (N = {args.n}), N precisa ser um inteiro.")
        quit(-1)

    try:
        probability = float(args.p)
    except ValueError:
        print(f"Valor invalido para a probablidade (p = {args.p}), precisa ser uma variável de ponto flutuante.")
        quit(-1)

    matrix = erdos_renyi(total_nodes, probability)

    for line in range(0, total_nodes):
        print(matrix[line])


if __name__ == "__main__":
    main()
