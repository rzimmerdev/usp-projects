# ========================================================================
# Author: Rafael Zimmer
# nUsp: 12542612

# About:
# This file contains code for the Assignment 3, in which an image is
# filtered in different domains using Fourier Transformations.
# ========================================================================
import imageio
import numpy as np


# Simple implementation of Root Mean Squared Error for two N dimensional numpy arrays
def rmse(original: np.ndarray, reference: np.ndarray) -> float:
    return np.sqrt(((original - reference) ** 2).mean())


def clsq(k: int, sigma: float, gamma: float) -> np.ndarray:
    """

    Args:
        k:
        sigma:
        gamma:

    Returns:

    """
    if not 0 <= gamma < 1:
        raise ValueError("Gamma not within valid range: [0, 1)")

    estimated_img = np.array(list())

    return estimated_img


def richardson_lucy(angle: int, steps: int) -> np.ndarray:
    """

    Args:
        angle:
        steps:

    Returns:

    """
    angle = angle % 180

    estimated_img = np.array(list())

    return estimated_img


def main():
    input_file = input()
    method = int(input())

    original = imageio.read(input_file)
    restored = np.array([])

    if method == 1:
        k = int(input())
        sigma = float(input())
        gamma = float(input())

        restored = clsq(k, sigma, gamma)

    elif method == 2:
        angle = int(input())
        steps = int(input())

        restored = richardson_lucy(angle, steps)

    print(rmse(original, restored))


if __name__ == "__main__":
    main()
