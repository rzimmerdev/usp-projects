// Rafael Zimmer, 12542612

#include <stdio.h>

// Declaring constants for particle position relative interactions
const int sand_physics[3][2] = {{1, 0}, {1, -1}, {1, 1}};
const int water_physics[5][2] = {{1, 0}, {1, -1}, {1, 1}, {0, -1}, {0, 1}};

// Function for swapping two chars directly in the field matrix, based on initial coordinates.
void swap_particle(char (*field)[34][66], int y1, int x1, int y2, int x2) {

	char tmp = (*field)[y1][x1];

	(*field)[y1][x1] = (*field)[y2][x2];
	(*field)[y2][x2] = tmp;

}

// Function for printing out entire field matrix, line by line, character by character, ignoring border blocks
void print_simulation(char simulation_field[34][66]) {

	for (int i = 1; i < 33; i++) {
		for (int j = 1; j < 65; j++) {
			printf("%c", simulation_field[i][j]);
		}

		printf("\n");
	}
}

// Function for assigning values in one field array to another (useful for creating field matrix copies)
void assign_array(char array1[34][66], char array2[34][66]) {
	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 66; j++) {
			array1[i][j] = array2[i][j];
		}
	}
}

// Function to execute physic interactions between field particles
void run_physics(char (*field)[34][66]) {

	// Create temporary field clone matrix, for swapping characters without interfering in physics calculations.
	// Should be noted that the field matrix has border blocks, which are not originated by stdin, but make calculating
	// out-of-bound particles easier. (Thus should not be considered when looking for particles to swap with)
	char temp[34][66];
	assign_array(temp, (*field));

	for (int i = 1; i < 33; i++) {
		for (int j = 1; j < 65; j++) {

			// Switch for deciding particle behavior
			switch ((*field)[i][j]) {

				case ('#'):

					// Sand particle has 3 cells than it can swap with, thus should decide if these cells are less dense
					for (int c = 0; c < 3; c++) {

						int compared_particle_y = i + sand_physics[c][0];
						int compared_particle_x = j + sand_physics[c][1];

						char compared_particle = (*field)[compared_particle_y][compared_particle_x];

						// If currently compared particle is air or water, should swap with sand.
						if (compared_particle == ' ' || compared_particle == '~') {
							swap_particle(&temp, i, j, compared_particle_y, compared_particle_x);
							break;
						}
					}
					break;

				// Water particle has 5 cells than it can swap with, thus should decide if these cells are less dense (air only)
				case ('~'):

					for (int c = 0; c < 5; c++) {

						int compared_particle_y = i + water_physics[c][0];
						int compared_particle_x = j + water_physics[c][1];

						char compared_particle = (*field)[compared_particle_y][compared_particle_x];

						// If currently compared particle is air, should swap with water.
						if (compared_particle == ' ') {
							swap_particle(&temp, i, j, compared_particle_y, compared_particle_x);
							break;
						}
					}
					break;

			}
		}
	}

	// Copy swapped values into original field matrix
	assign_array((*field), temp);
}

int main() {

	// Generate field with internal modifiable values, and assigning border blocks to cement particle, as borders have
	// the same behavior as cement
	char field[34][66] = { [ 1 ... 32 ] = { [ 1 ... 64 ] = ' ', [ 0 ] = '@', [ 65 ] = '@'},
						   [ 0 ] = { [ 0 ... 65 ] = '@' },
						   [ 33 ] = { [ 0 ... 65 ] = '@' },
						   };

	int total_frames; scanf("%d", &total_frames);

	// For loop for iterating through total frames, and performing physics calculations accordingly, as well as displaying
	// current field matrix status to console.
	for (int frame = 0; frame < total_frames; frame++) {

		int read_frame;

		// Scan stdin for new particles added to current frame, and place them in field grid
		while ( (scanf("%d", &read_frame) != EOF) && (read_frame == frame) ) {

			int scanned_particle_x;
			int scanned_particle_y;
			char scanned_particle_type;

			scanf(": %d %d %c", &scanned_particle_x, &scanned_particle_y, &scanned_particle_type);

			field[scanned_particle_y + 1][scanned_particle_x + 1] = scanned_particle_type;

		}

		// Lastly, print current field and execute physics calculations on frame end.
		printf("frame: %d\n", frame + 1);
		print_simulation(field);

		run_physics(&field);
	}
}