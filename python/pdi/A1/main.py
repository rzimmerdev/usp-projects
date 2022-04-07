from math import cos, sin
import random

import numpy as np
import matplotlib.pyplot as plt


def draw_f(size, function):

    image_f = np.zeros((size, size))

    for x_pos in range(size):
        for y_pos in range(size):
            image_f[x_pos, y_pos] = function(x_pos, y_pos)

    return image_f


def walk_f(size, function):

    image_f = np.zeros((size, size))

    pos_y, pos_x = (0, 0)

    for _ in range(1 + size * size):
        image_f[pos_x, pos_y] = 1

        pos_x, pos_y = function(pos_x, pos_y)

    return image_f


def normalize_matrix(matrix, max_range=1, min_range=0):
    matrix -= np.min(matrix)
    matrix /= (np.max(matrix) - np.min(matrix))
    matrix *= (max_range - min_range)
    matrix -= min_range


def digitise_image(original_image, original_size, final_size, max_bits):

    ratio = int(original_size / final_size)
    digitised_image = np.zeros((final_size, final_size))

    for y_pos in range(final_size):
        for x_pos in range(final_size):
            digitised_image[y_pos, x_pos] = original_image[y_pos * ratio, x_pos * ratio]

    digitised_image = (digitised_image * 255 / 65535).astype(np.ubyte)
    digitised_image = digitised_image >> 8 - max_bits

    return digitised_image


def rse(generated, reference):

    squared_error = np.square(generated - reference)

    return pow(np.sum(squared_error), 1/2)


def main():
    filename = str(input()).rstrip()
    size_c = int(input())
    function_index = int(input()) - 1
    param_q = int(input())
    size_n = int(input())
    num_bits = int(input())
    seed_s = str(input())

    random.seed(seed_s)    # Setting seed value for random module

    functions = [
        lambda x, y: x*y + 2*y,
        lambda x, y: abs(cos(x / param_q) + 2*sin(y / param_q)),
        lambda x, y: abs(3*(x / param_q) - pow((y / param_q), 1/3)),
        lambda x, y: random.random(),
        lambda x, y: ((x + random.randint(-1, 1)) % size_c, (y + random.randint(-1, 1)) % size_c)
    ]

    if function_index == 4:
        image_f = walk_f(size_c, functions[function_index])
    else:
        image_f = draw_f(size_c, functions[function_index])

    normalize_matrix(image_f, max_range=65535)
    image_g = digitise_image(image_f, size_c, size_n, num_bits)

    reference = np.load("test_cases/{}".format(filename))
    # reference = np.load(filename)

    reference = reference.astype(np.ubyte)

    plt.imshow(image_g, cmap="gray", vmin=0, vmax=np.max(image_g))
    plt.show()

    plt.imshow(reference, cmap="gray", vmin=0, vmax=np.max(reference))
    plt.show()

    error = rse(image_g, reference)
    return error


if __name__ == "__main__":
    err = main()
    print("{:.4f}".format(err))
