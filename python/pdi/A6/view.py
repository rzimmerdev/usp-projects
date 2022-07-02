import matplotlib.pyplot as plt


def show_images(*args, cmap=None):
    for image in args[0]:
        plt.figure(figsize=(16, 16))
        if cmap:
            plt.imshow(image, cmap=cmap)
        else:
            plt.imshow(image)
        plt.show()
