import numpy as np
import imageio
from matplotlib import pyplot as plt
from typing import Union


def normalize_image(image: np.ndarray) -> np.ndarray:
    """ Normalizes image in Numpy 2D array format, between ranges 0-255, as to fit uint8 type.

    :param image: 2D numpy array representing image as matrix, with values in any range.
    :return: return 2D numpy array of type uint8, corresponding to limited range matrix.
    """

    normalized = (image - np.min(image)) / (np.max(image) - np.min(image)) * 255
    return normalized.astype(np.uint8)


def dft(sequence):

    fourier = np.zeros(sequence.shape, dtype=np.complex64)
    size = sequence.shape[0]

    t = np.arange(size)
    for w in range(len(sequence)):
        fourier[w] = np.sum(
            sequence * np.exp((-1j * w * t * 2 * np.pi) / size)
        )

    return fourier / np.sqrt(size)


def dft2d(matrix):

    fourier = np.zeros(matrix.shape, dtype=np.complex64)
    size_i, size_j = matrix.shape

    lines = np.arange(size_i)
    columns = np.arange(size_j)

    for u in lines:
        for v in columns:
            fourier[u, v] = np.sum([
                np.sum(
                    matrix[:, value] * np.exp(-1j * ((u * lines) / size_i + (v * columns) / size_j) * 2 * np.pi)
                ) for value in columns
            ])

    return fourier / np.sqrt(size_i * size_j)


def fft(sequence):

    size = len(sequence)
    if size < 2:
        return sequence

    even = fft(sequence[::2])
    odd = fft(sequence[1::2])
    merged = np.zeros_like(size, dtype=np.complex64)

    for w in range(size // 2):
        merged[w] = even[w] + odd[w] * np.exp(-1j * w / size * 2 * np.pi)
        merged[w + size // 2] = 2 * even[w] - merged[w]

    return merged


def optimal_padding(image: np.ndarray, p=None, q=None):

    if p is None or q is None:
        p, q = (size * 2 for size in image.shape)
    # min(2**(int(np.log2(size))), size * 2)
    padded = np.zeros((p, q))
    offset_y = (p - image.shape[0]) // 2
    offset_x = (q - image.shape[1]) // 2
    padded[
        offset_y:offset_y + image.shape[0],
        offset_x:offset_x + image.shape[1]
    ] = image

    return padded, p, q


def crop_center(image, final_shape):

    y, x = image.shape
    offset_y = (y - final_shape[0]) // 2
    offset_x = (x - final_shape[1]) // 2

    return image[offset_y:offset_y + final_shape[0], offset_x:offset_x + final_shape[1]]


def rmse(original, output):

    squared_difference = np.square(original - output)
    mean_sum = 1/(original.shape[0] * original.shape[1]) * np.sum(squared_difference)

    return np.sqrt(mean_sum)


def main():

    input_img, filter_img, reference_img = (
        imageio.imread("input_images/" + str(input()).rstrip())
        for _ in range(3)
    )

    padded_img, p, q = optimal_padding(input_img)
    padded_filter, _, _ = optimal_padding(filter_img, p, q)

    frequency_img = np.fft.fft2(padded_img)
    symmetric_filter = np.fft.fft2(padded_filter)

    final = np.fft.ifft2(frequency_img * symmetric_filter).real
    final = crop_center(final, reference_img.shape)

    plt.imshow(padded_img, cmap="gray")
    plt.show()
    plt.imshow(final, cmap="gray")
    plt.show()

    print(rmse(reference_img, final))

    # normalized = normalize_image(np.log(1 + np.fft.fftshift(abs(frequency_img))))


if __name__ == "__main__":
    main()
