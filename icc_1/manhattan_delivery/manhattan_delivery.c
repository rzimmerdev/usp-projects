// Rafael Zimmer, n 12542612

#include <stdio.h>
#include <math.h>

// Function for returning distance between coordinates as absolute value
int abs (int n) {
	if (n >= 0) return n;
	else return -n;
}

int switch_routes(int prev_coords[], int x, int y, int *parks, int *residential, int *empty, double *difference) {

	// Depending on type of terrain, either ignore difference and increment terrain counter,
	// or evaluate difference between distance traveled outside and inside terrain, adding to total amount
	switch (prev_coords[2]) {
		case 1:
			*parks += 1;
			*difference += abs(x-prev_coords[0]) + abs(y-prev_coords[1])
						   -sqrt(pow(x-prev_coords[0], 2) + pow(y-prev_coords[1], 2));
			return 1;
			break;

		case 0:
			*residential += 1;
			return 1;
			break;

		case -1:
			*empty += 1;
			return 1;
			break;

		default:
			printf("Falha no processamento dos dados.\n");
			return 0;

	}
}

int main() {

	// Scan total routes
	int total_routes;

	scanf("%i", &total_routes);

	// Decide if route amount is valid
	if (total_routes < 0) {

		printf("Falha no processamento dos dados.\n");
		return 0;
	}

	// Scan initial coordinates
	int first_coords[3];

	scanf("%d %d %d", &first_coords[0], &first_coords[1], &first_coords[2]);

	// As loop starts counting from first destination, save previous route destination
	int prev_coords[3] = { first_coords[0], first_coords[1], first_coords[2] };

	// Initialize difference between Hermann's and Euclides' routes and the number of each terrain type passed
	double difference = 0;
	int residential = 0, empty = 0, parks = 0;

	for (int i = 1; i < total_routes; i++) {

		// Scan coordinates and type of terrain
		int x, y, type;

		scanf("%d %d %d", &x, &y, &type);

		// Call function to increment terrain type counter, as well as routes distance difference calculator
		if (!switch_routes(prev_coords, x, y, &parks, &residential, &empty, &difference)) {
			return 0;
		}

		prev_coords[0] = x, prev_coords[1] = y, prev_coords[2] = type;

	}

	// Evaluate return to home
	if (!switch_routes(prev_coords, first_coords[0], first_coords[1], &parks, &residential, &empty, &difference)) {
		return 0;
	}

	// Print formatted result
	printf("Ao todo, foi passado por %d terrenos baldios, %d terrenos residenciais e %d parques.\n"
		   "A diferenca total de distancia percorrida foi de %.2lf metros.", empty, residential, parks, difference);

	return 0;

}