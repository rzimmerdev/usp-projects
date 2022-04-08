from random import seed, random
import argparse, sys
# import numpy as np


def erdos_renyi(n: int, p: float):
    if not 0 < p < 1:
        raise ValueError(f"Valor invalido p: {p}, precisa estar entre 0 e 1.")

    if n < 0:
        raise ValueError(f"Valor invalido n: {n}, precisa ser maior que 0.")

    mat = [[0 for x in range(n)] for _ in range(n)]
    # mat = np.zeros((n, n))

    for i in range(0, n - 1):
        for j in range(i + 1, n):
            if random() < p:
                mat[i][j] = 1
                mat[j][i] = 1

    return mat


def main():

    parser = argparse.ArgumentParser()

    try:
        matrix_size = int(sys.argv[1])
    except ValueError:
        print("Valor invalido para tamanho da matriz, formato esperado:")
        quit(-1)

    try:
        matrix_size = int(sys.argv[1])
    except ValueError:
        print("Valor invalido para tamanho da matriz, formato esperado:")
        quit(-1)

    matrix = erdos_renyi(matrix_size, 0.3)

    for line in range(0, matrix_size):
        print(matrix[line])


if __name__ == "__main__":
    main()
