# ========================================================================
# Author: Rafael Zimmer
# nUsp: 12542612

# About:
# This file contains code for the Assignment 5, which serves as a study for different
# image descriptors and morphology
# ========================================================================
import imageio
import numpy as np


def rmse(original: np.ndarray, reference: np.ndarray) -> float:
    """Simple implementation of Root Mean Squared Error for two N dimensional numpy arrays."""
    return np.sqrt(((original - reference) ** 2).mean())


def normalize_image(image: np.ndarray, cap: float = 255) -> np.ndarray:
    """Normalizes image in Numpy 2D array format, between ranges 0-cap, as to fit uint8 type.

    Args:
        image: 2D numpy array representing image as matrix, with values in any range
        cap: Maximum cap amount for normalization
    Returns:
        return 2D numpy array of type uint8, corresponding to limited range matrix
    """
    normalized = (image - np.min(image)) / (np.max(image) - np.min(image)) * cap
    return normalized.astype(np.uint8)


def normalize_array(array, cap: float = 1):
    """Normalizes a 1D array, between ranges 0-cap.

    Args:
        array: List containing values to be normalized between cap range.
        cap: Maximum cap amount for normalization.
    Returns:
        return 1D numpy array , corresponding to limited range array
    """
    normalized = (array - np.min(array)) / (np.max(array) - np.min(array)) * cap
    return normalized


def euclidean(point_1: np.ndarray, point_2: np.ndarray):
    """Simple method for calculating the euclidean distance between two points, with type np.ndarray."""
    return np.sqrt(np.sum(np.square(point_1 - point_2)))


def grayscale(image: np.ndarray) -> np.ndarray:
    """Uses luminance weights to transform RGB channel to greyscale, by
    taking the dot product between the channel and the weights."""
    return np.dot(image[:, :, 0:3], [0.299, 0.587, 0.114]).astype(np.uint8)


def main():
    # Read filename for input and reference images
    input_filename, reference_filename = input().rstrip(), input().rstrip()

    # Reads the image type to be used, can be either
    # 1.    (R, G, B)
    # 2.    (R, G, B, x, y)
    # 3.    (Luminance)
    # 4.    (Luminance, x, y)
    image_type = int(input())

    # Reads the value k of clusters for the kNN algorithm, as well as the total iterations N.
    total_clusters, total_iterations = int(input()), int(input())

    # Seed to be used for the random centroids
    seed = int(input())





if __name__ == "__main__":
    main()
