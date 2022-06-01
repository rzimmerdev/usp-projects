# ========================================================================
# Author: Rafael Zimmer
# nUsp: 12542612

# About:
# This file contains code for the Assignment 4, in which an image with
# Motion Blur and noise is restored, even if containing zero valued pixels.
# ========================================================================
import imageio
import numpy as np
from numpy.fft import fft2, ifft2, ifftshift


def rmse(original: np.ndarray, reference: np.ndarray) -> float:
    """Simple implementation of Root Mean Squared Error for two N dimensional numpy arrays."""
    return np.sqrt(((original - reference) ** 2).mean())


def pad_to_size(image: np.ndarray, reference: np.ndarray):
    """Pad an image to have final shape equal to reference image."""
    p, q = (size for size in reference.shape)
    difference = ((p - image.shape[0]) // 2, (q - image.shape[1]) // 2 + (q - image.shape[1]) % 2)

    return np.pad(image, difference, mode='constant')


def normalize_image(image: np.ndarray) -> np.ndarray:
    """ Normalizes image in Numpy 2D array format, between ranges 0-255, as to fit uint8 type.

    :param image: 2D numpy array representing image as matrix, with values in any range
    :return: return 2D numpy array of type uint8, corresponding to limited range matrix
    """
    normalized = (image - np.min(image)) / (np.max(image) - np.min(image)) * 255
    return normalized.astype(np.uint8)


def gaussian_noise(size: tuple, mean=0, std=0.05):
    """Creates normal distribution array with given size to use as noise."""
    noise = np.multiply(np.random.normal(mean, std, size), 255)
    return noise


def gaussian_filter(k: int = 5, sigma: float = 1.0) -> np.ndarray:
    """Generates a matrix with weights corresponding to centered gaussian distribution.

    Args:
        k: Lateral size of the kernel.
        sigma: Standard deviation to be used when generating distribution

    Returns:
        np.ndarray: [k x k] sized kernel to be used as filter
    """
    arx = np.arange((-k // 2) + 1.0, (k // 2) + 1.0)
    x, y = np.meshgrid(arx, arx)
    filt = np.exp(-(1 / 2) * (np.square(x) + np.square(y)) / np.square(sigma))
    return filt / np.sum(filt)


def convolve(matrix: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    """Convolves a given kernel around a matrix through the frequency domain, using Fourier transformations.

    Args:
        matrix: Numpy array containing values to be convolved
        kernel: Kernel (with all dimensions smaller than those of the matrix) with weights to apply to each pixel.

    Returns:
        np.ndarray: Final equally shaped matrix with convoluted pixels.
    """
    if kernel.shape[0] > matrix.shape[1] or kernel.shape[1] > matrix.shape[1]:
        return matrix
    kernel = pad_to_size(kernel, matrix)

    kernel_f = fft2(kernel)
    matrix_f = fft2(matrix)

    return ifftshift(ifft2(np.multiply(matrix_f, kernel_f))).real


def get_motion_psf(shape: tuple, angle: float, num_pixel_dist: int = 20) -> np.ndarray:
    """Generate an array with given shape corresponding to Point Spread Function for the desired angle.

    Parameters:
        shape: The shape of the image.
        angle: The angle of the motion blur. Should be in degrees. [0, 360)
        num_pixel_dist: The distance of the motion blur. [0, infinity)
            Remember that the distance is measured in pixels. Greater will be more blurry

    Returns:
        np.ndarray: The point-spread array associated with the motion blur.
    """
    psf = np.zeros(shape)
    center = np.array([shape[0] - 1, shape[0] - 1]) // 2
    radians = angle / 180 * np.pi
    phase = np.array([np.cos(radians), np.sin(radians)])
    for i in range(num_pixel_dist):
        offset_x = int(center[0] - np.round_(i * phase[0]))
        offset_y = int(center[1] - np.round_(i * phase[1]))
        psf[offset_x, offset_y] = 1
    psf /= psf.sum()

    return psf


def clsq(degraded_f: np.ndarray, function_f: np.ndarray, gamma: float) -> np.ndarray:
    """Constrained Least Squares method to restore image affected by known degradation function and noise.

    Args:
        degraded_f: Degraded image to be restored
        function_f: Degradation function used to convolve around original image
        gamma: Regularization parameter used to weigh the laplacian operator

    Returns:
        np.ndarray: Restored image after method application
    """
    if not 0 <= gamma < 1:
        raise ValueError("Gamma not within valid range: [0, 1)")

    laplacian = np.array(
        [[0, -1, 0],
         [-1, 4, -1],
         [0, -1, 0]
         ])

    padded = pad_to_size(laplacian, function_f)
    padded_f = fft2(padded)
    estimated_img_f = np.multiply(
        np.divide(function_f.transpose(),
                  (function_f * function_f.conjugate() + gamma * padded_f * padded_f.conjugate())),
        degraded_f
    )
    estimated_img = ifftshift(ifft2(estimated_img_f).real)

    return np.clip(estimated_img, 0, 255)


def richardson_lucy(degraded: np.ndarray, function: np.ndarray, steps: int) -> np.ndarray:
    """Richardson-Lucy method to restore an image affected by known motion blur function, as well as arbitrary steps
    to perform during iterative image restoration.

    Args:
        degraded: Observed image, considered to be degraded - to be restored
        function: Supposed function used to blur original image
        steps: Iterative steps to take for restoring image

    Returns:
        np.ndarray: Restored image after method application
    """
    estimated_img = np.full(shape=degraded.shape, fill_value=1, dtype="float64")

    for i in range(steps):
        dividend = convolve(estimated_img, function)
        quotient = np.divide(degraded, dividend, where=dividend != 0)

        estimated_img = np.multiply(estimated_img,
                                    convolve(quotient, np.flip(function)))

        estimated_img = np.clip(estimated_img, 0, 255)

    return estimated_img


def main():
    input_file = str(input()).rstrip()
    method = int(input())

    original = imageio.imread(input_file)
    restored = np.array([])

    # --------------------------------------------------- #
    # Switch selected method to perform image restoration
    # --------------------------------------------------- #
    # Method 1 uses the Constrained Least Squares method to restore an image
    # degraded by gaussian blur and gaussian noise.
    #
    # Method 2 uses the Richardson-Lucy iterative method to restore an image
    # degraded by motion blur and noise.
    if method == 1:
        k = int(input())
        sigma = float(input())
        gamma = float(input())

        h = pad_to_size(gaussian_filter(k, sigma), original)
        original_f = fft2(original)
        function_f = fft2(h)

        degraded_f = np.multiply(original_f, function_f)
        degraded = np.fft.ifftshift(np.fft.ifft2(degraded_f).real)
        degraded_noisy = np.clip(degraded + gaussian_noise(original.shape), 0, 255)
        degraded_noisy_f = fft2(degraded_noisy)

        restored = clsq(degraded_noisy_f, function_f, gamma)

    elif method == 2:
        angle = int(input())
        steps = int(input())

        restored = richardson_lucy(original, get_motion_psf(original.shape, angle), steps)

    print(rmse(original, restored))


if __name__ == "__main__":
    main()
