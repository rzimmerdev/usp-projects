# ========================================================================
# Author: Rafael Zimmer
# nUsp: 12542612

# About:
# This file contains code for the Assignment 5, which serves as a study for different
# image descriptors and morphology
# ========================================================================
import imageio
import numpy as np
import random


def rmse(original: np.ndarray, reference: np.ndarray) -> float:
    """Simple implementation of Root Mean Squared Error for two N dimensional numpy arrays."""
    return np.sqrt(((original - reference) ** 2).mean())


def normalize_image(image: np.ndarray, cap: float = 255) -> np.ndarray:
    """Normalizes image in Numpy 3D RGB image format, between ranges 0-cap, as to fit uint8 type.

    Args:
        image: 3D numpy array representing RGB image as matrix, with values in any range
        cap: Maximum cap amount for normalization
    Returns:
        return 3D numpy array of type uint8, corresponding to limited range matrix
    """
    normalized = np.zeros_like(image)
    for i in range(3):
        current_channel = image[:, :, i]
        normalized[:, :, i] = (current_channel - np.min(current_channel)) / \
                              (np.max(current_channel) - np.min(current_channel)) * cap
    return normalized.astype(np.uint8)


def normalize_array(array, cap: float = 1) -> np.ndarray:
    """Normalizes a 1D array, between ranges 0-cap.

    Args:
        array: List containing values to be normalized between cap range.
        cap: Maximum cap amount for normalization.
    Returns:
        return 1D numpy array , corresponding to limited range array
    """
    normalized = (array - np.min(array)) / (np.max(array) - np.min(array)) * cap
    return normalized


def euclidean(first: np.ndarray, last: np.ndarray, axis: int = None):
    """Simple method for calculating the euclidean distance between points, with type np.ndarray."""
    return np.sqrt(np.sum(np.square(first - last), axis=axis))


def grayscale(image: np.ndarray) -> np.ndarray:
    """Uses luminance weights to transform RGB channel to greyscale, by
    taking the dot product between the channel and the weights."""
    return np.dot(image[:, :, 0:3], [0.299, 0.587, 0.114])


def initialize_clusters(image, total_clusters):
    """Creates an array of random ids within given flattened image size,
    for using when instantiating new centroids values."""
    size = image.shape[0] * image.shape[1]
    ids = np.sort(random.sample(range(0, size), total_clusters))
    return ids


def map_distances(centroids, flatten, params):
    """Calculates the distance of each pixel within the flattened image to each centroid,
    taking into account the desired vector parameters to use"""
    distances_map = np.zeros((flatten.shape[0], len(centroids)), dtype=np.float32)

    for idx, centroid in enumerate(centroids):
        distance_to_centroid = euclidean(flatten[:, 0:params], centroid, axis=1)
        distances_map[:, idx] = distance_to_centroid

    labels_mask = np.argmin(distances_map[:, :], axis=1)
    return labels_mask


def kneighbours_classifier(image, total_clusters, total_iterations, image_type):
    """Generates a label mask for the given image.
    Uses the kneareset neighbours algorithm for performing classification on the given image.
    Resulting labeled mask contains the selected k number of labeled groups.

    Args:
        image: Original image to perform nearest neighbours segmentation.
        total_clusters: How many centroids should the image be separated into.
        total_iterations: Total convergence steps to be taken when recalculating centroids
        image_type: Original image type, defining which color code to use, as well as which encoding,
                    being either (RGB; RGB + X,Y; L; L + X, Y).
    Returns:
        Label mask for the given image, with clusters number of different groups.
    """
    # Vectorize image and initialize centroids with random indices
    flatten = image.reshape((image.shape[0] * image.shape[1], -1))
    centroids = flatten[initialize_clusters(image, total_clusters)]

    # Decide how many color channels the image has based on its type,
    # as well as which encoding to use (only color channels or use coordinates as well).
    channels = 3 if image_type in {1, 2} else 1
    params = channels
    if image_type in {2, 4}:
        params += 2

    for i in range(total_iterations - 1):
        # For each centroid, calculate the distance between its channels and each individual pixel within
        # the flattened image. Then, attribute to each position the id of the centroid to which the current pixel
        # has the smallest distance.
        # centroids: array with position of each centroid
        # flatten: flattened original image
        labels_mask = map_distances(centroids, flatten, params)

        for idx in range(len(centroids)):
            values = flatten[np.argwhere(labels_mask == idx)]
            if values.size != 0:
                centroids[idx] = np.mean(values, axis=1).mean(axis=0)

    labels_mask = map_distances(centroids, flatten, params)

    # Normalize each color channel within the centroids
    colors = centroids[:, 0:channels]
    for channel in range(channels):
        colors[:, channel] = normalize_array(colors[:, channel], 255)

    # Then, assing to each pixel within the original image
    # its color based on the centroid to which it is closest
    labels = labels_mask.reshape((image.shape[0], image.shape[1], -1))
    for idx in range(len(centroids)):
        labels = np.where(labels == idx, colors[idx], labels)

    return labels.astype(np.float32)


def main():
    # Read filename for files and reference images
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
    random.seed(seed)

    input_image = imageio.imread(input_filename).astype(np.float64)
    reference_image = imageio.imread(reference_filename).astype(np.float64)

    # If image is of type gray, convert to grayscale using Luminance formulae
    # Then, add an empty third dimension to use with generic KNN function
    if image_type in {3, 4}:
        input_image = grayscale(input_image).reshape((input_image.shape[0], input_image.shape[1], 1))
        reference_image = reference_image.reshape((input_image.shape[0], input_image.shape[1], 1))

    # If image is of type channels + coordinates (RGB + X,Y or L + X,Y)
    # append the axis values to each channel value
    if image_type in {2, 4}:
        i, j = np.indices(input_image.shape[0:2])
        input_image = np.append(input_image, i[:, :, np.newaxis], axis=2)
        input_image = np.append(input_image, j[:, :, np.newaxis], axis=2)
    labeled_image = kneighbours_classifier(input_image, total_clusters, total_iterations, image_type)

    # Print error as a sum of errors within all color channels
    channels = 3 if image_type in {1, 2} else 1
    error = 0
    for color in range(channels):
        error += rmse(labeled_image[:, :, color], reference_image[:, :, color])
    print(error)


if __name__ == "__main__":
    main()
