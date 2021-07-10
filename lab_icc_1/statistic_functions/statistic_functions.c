// Rafael Zimmer, n 12542612

#include <stdio.h>
#include <stdlib.h>

// Defining functions for finding highest and lowest numbers
#define MAX(A, B) ((A > B) ? A : B)
#define MIN(A, B) ((A > B) ? B : A)

int compare(const void *a, const void *b) {
	int va = *(const int *) a;
	int vb = *(const int *) b;
	return (va > vb) - (va < vb);
}

int main() {

	int values[10] = { };

	// Start maximum value and minimum value possible for int, for comparison purposes (inverse is valid for min)
	int max = -1;
	int min = 100000;
	int sum = 0;
	int mode = 0;

	// Iterate through input
	for (int i = 0; i < 10; i++) {

		int number;
		scanf("%d", &number);

		max = MAX(number, max);
		min = MIN(number, min);
		sum += number;
		values[i] = number;

	}

	// Sort array of values for finding most frequent
	qsort(values, 10, 4, compare);

	// Decide which input was the most frequent, and find mode
	int frequency = 0;
	int most_frequent = 0;
	mode = values[0];

	for (int i = 1; i < 10; i++) {

		frequency++;

		if (frequency > most_frequent) {

			mode = values[i-1];
			most_frequent = frequency;

		}

		if (values[i - 1] != values[i]) frequency = 0;

	}

	printf("%d %d %.2f %d", max, min, (double) sum / 10, mode);

	return 0;

}