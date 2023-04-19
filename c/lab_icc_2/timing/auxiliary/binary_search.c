int binary_search(int *array, int higher, int lower, int value) {

	if (higher >= lower) {

		int center = lower + (higher - lower) / 2;
		if (array[center] == value) { return center; }
		if (array[center] > value) { return binary_search(array, center - 1, lower, value); }
		return binary_search(array, higher, center + 1, value);
	}
	return -1;
}