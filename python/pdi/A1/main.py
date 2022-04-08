from math import cos, sin
import random

import numpy as np


#
def draw_f(size: int, function):
    """ Draws a new image using given function, setting pixel values
        to output of function with dimensions x and y as parameters.

    :param size: Height and width of generated image.
    :param function: Function to generate pixel values at specific x and y coordinates.
    :return: Returns a np.ndarray with shape=(size, size).
    """

    image_f = np.zeros((size, size))

    for x_pos in range(size):
        for y_pos in range(size):
            image_f[x_pos, y_pos] = function(x_pos, y_pos)

    return image_f


def walk_f(size: int, function):
    """ Performs a random walk through generated 2D image, setting
        pixels to value 1

    :param size: Height and width of generated image.
    :param function: Function that returns next position, given previous position.
    :return: Returns a np.ndarray with shape=(size, size).
    """

    image_f = np.zeros((size, size))

    pos_y, pos_x = (0, 0)

    for _ in range(1 + size * size):
        image_f[pos_y, pos_x] = 1

        pos_y, pos_x = function(pos_y, pos_x)

    return image_f


def normalize_matrix(matrix: np.ndarray, max_range=1, min_range=0):
    """ Scales matrix values between given range, using normalization

    :param matrix: Original matrix with values to scale, of type np.ndarray
    :param max_range: Maximum range to be scaled to
    :param min_range: Minimum range to be scaled to
    :return: No returning parameter, operation is in place
    """

    matrix -= np.min(matrix)
    matrix /= (np.max(matrix) - np.min(matrix))
    matrix *= (max_range - min_range)
    matrix -= min_range


def digitise_image(original_image: np.ndarray, final_size: int, max_bits: int):
    """ Crates new image with final_size, passing pixel values from original_image
        using relative ratio between original_size and final_size as the step
        value for indexing pixels.

        The final image is then reduced to 8 bits, and compressed into max_bits using
        a bit-shift operation.

    :param original_image: 2D Array containing pixel values for image to be digitized.
    :param final_size: Size of desired digitized image.
    :param max_bits: Maximum bits to be preserved of original image.
    :return:
    """

    ratio = int(original_image.shape[0] / final_size)
    digitised_image = np.zeros((final_size, final_size))

    for y_pos in range(final_size):
        for x_pos in range(final_size):
            digitised_image[y_pos, x_pos] = original_image[y_pos * ratio, x_pos * ratio]

    digitised_image = (digitised_image * 255 / 65535).astype(np.ubyte)
    digitised_image = digitised_image >> 8 - max_bits

    return digitised_image


def rse(generated: np.ndarray, reference: np.ndarray):
    """ Calculates root squared error of values in generated 2D Array with respect to reference 2D Array.

    :param generated: 2D Array with values to be subtracted from.
    :param reference: 2D reference Array to calculate error on.
    :return: Absolute value of root from squared difference.
    """

    squared_error = np.square(generated - reference)

    return pow(np.sum(squared_error), 1/2)


def main():

    # Below, parameters for new image generation and digitization are scanned from console.
    filename = str(input()).rstrip()
    size_c = int(input())
    function_index = int(input()) - 1
    param_q = int(input())
    size_n = int(input())
    num_bits = int(input())
    seed_s = int(input())

    random.seed(seed_s)    # Setting seed value for random module

    # Functions to pass when drawing new image, or when performing random walk
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

    # Here, the drawn image is first normalized to range(0, 65535), then digitized into image_g
    normalize_matrix(image_f, max_range=65535)
    image_g = digitise_image(image_f, size_n, num_bits)

    # The reference image is then loaded from Numpy Load files with given name,
    # then the Root Squared Error is calculated and returned for printing
    reference = np.load(filename).astype(np.ubyte)

    error = rse(image_g, reference)
    return error


if __name__ == "__main__":
    err = main()
    print("{:.4f}".format(err))
