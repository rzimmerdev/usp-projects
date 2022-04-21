# ========================================================================
# Name: Rafael Zimmer
# nUsp: 12542612
# About:
# This file contains code for the Assignment 2, in which an image is
# enhanced, or different filters are applied to it.
# ========================================================================

import numpy as np
import imageio
import matplotlib.pyplot as plt
import math


def main():
    filename = str(input())
    method = int(input())

    image = imageio.imread("test_cases/" + filename)

    if method == 1:

        threshold = int(input())
        final = limiarization(image, threshold)

    elif method == 2:

        size_n = int(input())
        weights = [int(x) for x in input().split()]

        final = dim1_filtering(image, weights)

    elif method == 3:

        size_n = int(input())
        mat = np.zeros(size_n, size_n)

        for i in range(size_n):
            for j in range(size_n):
                mat[i][j] = int(input())
        threshold = int(input())

    elif method == 4:

        size_n = int(input())

    print(f"{rmse(original=image, output=final):.4f}")


def rmse(original, output):

    squared_difference = np.square(original - output)
    mean_sum = 1/(original.shape[0] * original.shape[1]) * np.sum(squared_difference)

    return math.sqrt(mean_sum)


def limiarization(img, threshold):

    prev = -1

    while abs(threshold - prev) > 0.5:

        copy = np.array(img)
        for i in range(img.shape[0]):
            for j in range(img.shape[1]):
                copy[i][j] = 1 if copy[i][j] > threshold else 0

        region_1 = np.sum(np.where(copy, img, 0))
        region_2 = np.sum(img) - region_1

        num_positives = np.sum(copy)
        prev = threshold
        threshold = 1/2 * (region_1 / num_positives + region_2 / (img.shape[0] * img.shape[1] - num_positives))

    return [[0 if p < threshold else 255 for p in line] for line in img]


def dim1_filtering(img, filter_weights):
    vectorized = np.array(img.reshape(img.shape[0] * img.shape[1]))
    len_vector = len(vectorized)

    len_weights = len(filter_weights)
    weights_range = list(range(int((-len_weights + 1) / 2), int((len_weights - 1) / 2) + 1))

    for pos in range(len_vector):

        relative_sum = 0

        for w in range(len_weights):
            relative_sum += vectorized[(pos + weights_range[w]) % len_vector] * filter_weights[w]
            print((pos + weights_range[w]) % len_vector, end=" ")
        print("")

        vectorized[pos] = relative_sum

    plt.imshow(img, cmap="gray")
    plt.show()
    plt.imshow(vectorized.reshape(img.shape[0], -1), cmap="gray")
    plt.show()

    return vectorized.reshape(img.shape[0], -1)


if __name__ == "__main__":
    main()
