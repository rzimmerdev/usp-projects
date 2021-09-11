// Rafael Zimmer, nUsp 12542612

#include <stdio.h>

int main() {

	int input[100];
	int current_int, total_inputs = 0;

	while (scanf("%d ", &current_int) != EOF) {
		input[total_inputs] = current_int;
		total_inputs++;
	}

	// Counter array, with input value as identifier (index 0), and counter value as value (index 1)
	// Counter pos for determining current total of unique values, as well as counter header position
	int counter[100][2] = { }, counter_pos = 0;

	for (int i = 0; i < total_inputs; i++) {

		int is_accounted = 0;

		// Iterate over counter array to verify if current input is already indexed
		for (int j = 0; j < counter_pos; j++) {

			// If is indexed, increment count by 1
			if (counter[j][0] == input[i] && counter[j][1] > 0) {
				counter[j][1]++;
				is_accounted = 1;
				break;
			}
		}

		// If is not indexed, index value, increase header position and start counting at 1
		if (!is_accounted) {
			counter[counter_pos][0] = input[i];
			counter[counter_pos++][1] = 1;
		}
	}

	// Print, in input order, input value and total count for respective value
	for (int i = 0; i < counter_pos; i++) {
		printf("%d (%d)\n", counter[i][0], counter[i][1]);
	}

	return 0;
}