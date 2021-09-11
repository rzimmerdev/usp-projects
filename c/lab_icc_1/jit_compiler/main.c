// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - JIT compiler for BF
// 28/07/2021

#include <stdio.h>
#include <stdlib.h>

// Enum for evaluating different BF operators on iostream input
typedef enum {

	INCREMENT = '+',
	DECREMENT = '-',
	INDEX_INCREMENT = '>',
	INDEX_DECREMENT = '<',
	PRINT_VALUE = '.',
	LOOP_START = '[',
	LOOP_END = ']'

} BF_operations;

void print_file_beginning(FILE *file_pointer);
void print_file_ending(FILE *file_pointer);

void print_formatting(char current_operation, char previous_operation, int *current_command_count, int current_tabbing, FILE *file_pointer);

int main() {

	FILE *file_pointer = fopen("jit-gerado.c", "w");

	// Print beginning of .c program, as well as initiate variables for BF translation
	print_file_beginning(file_pointer);

	char current_operation, previous_operation = '.';
	int current_tabbing = 1, current_command_count = 0;

	// Scan input file, and evaluate process for each read BF operation in input file
	while (scanf("%c", &current_operation) != EOF) {

		switch (current_operation) {
			case (INCREMENT): {

				// Formatting line before inserting command to file
				print_formatting(current_operation, previous_operation, &current_command_count, current_tabbing, file_pointer);

				fprintf(file_pointer, "mem[i]++;");

			} break;

			case (DECREMENT): {

				// Formatting line before inserting command to file
				print_formatting(current_operation, previous_operation, &current_command_count, current_tabbing, file_pointer);

				fprintf(file_pointer, "mem[i]--;");

			} break;

			case (INDEX_INCREMENT): {

				// Formatting line before inserting command to file
				print_formatting(current_operation, previous_operation, &current_command_count, current_tabbing, file_pointer);

				fprintf(file_pointer, "i++;");

			} break;

			case (INDEX_DECREMENT): {

				// Formatting line before inserting command to file
				print_formatting(current_operation, previous_operation, &current_command_count, current_tabbing, file_pointer);

				fprintf(file_pointer, "i--;");

			} break;

			case (PRINT_VALUE): {

				if (current_operation != previous_operation)  fprintf(file_pointer, "\n");
				for (int i = 0; i < current_tabbing; i++) fprintf(file_pointer, "\t");
				fprintf(file_pointer, "putchar(mem[i]);\n");

			} break;

			case (LOOP_START): {

				// Formatting line before inserting command to file
				print_formatting(current_operation, previous_operation, &current_command_count, current_tabbing, file_pointer);

				fprintf(file_pointer, "while(mem[i]) {");
				current_tabbing++;

			} break;

			case (LOOP_END): {

				current_tabbing--;
				// Formatting line before inserting command to file
				print_formatting(current_operation, previous_operation, &current_command_count, current_tabbing, file_pointer);

				fprintf(file_pointer, "}");

			} break;
		}

		// Keep track of previous operation for formatting purposes
		previous_operation = current_operation;

	};

	// Print .c file ending, as well as printing non-empty values of memory to console
	print_file_ending(file_pointer);

	fclose(file_pointer);

	system("gcc jit-gerado.c -o jit-exe");
	system("./jit-exe");

	return 0;

}

void print_file_beginning(FILE *file_pointer) {

	fprintf(file_pointer, "#include <stdio.h>\n");
	fprintf(file_pointer, "\n");
	fprintf(file_pointer, "int main() {\n");
	fprintf(file_pointer, "\n");
	fprintf(file_pointer, "\tchar mem[30000] = { 0 };\n");
	fprintf(file_pointer, "\tint i = 0;\n");
	fprintf(file_pointer, "\n");
	fprintf(file_pointer, "\t/* Beginning of compiled code */");

}

void print_file_ending(FILE *file_pointer) {

	fprintf(file_pointer, "\n\n");
	fprintf(file_pointer, "\t/* End of compiled code */\n");
	fprintf(file_pointer, "\n");
	fprintf(file_pointer, "\tprintf(\"\\n\");\n");
	fprintf(file_pointer, "\tfor (int j = 0; j < 30000; j++) {\n");
	fprintf(file_pointer, "\t\tif (mem[j] != 0) {\n");
	fprintf(file_pointer, "\t\t\tprintf(\"%%d \", mem[j]);\n");
	fprintf(file_pointer, "\t\t}\n");
	fprintf(file_pointer, "\t}\n");
	fprintf(file_pointer, "\tprintf(\"\\n\");\n\n");
	fprintf(file_pointer, "}\n");

}

// Function for determining whether or not to skip line, how many tabs to add and if to add space between operators
// all of which are evaluated for each command translated and correspond to the .c formatting of the output file
void print_formatting(char current_operation, char previous_operation, int *current_command_count, int current_tabbing, FILE *file_pointer) {

	if (current_operation != previous_operation) {

		fprintf(file_pointer, "\n\n");
		for (int i = 0; i < current_tabbing; i++) fprintf(file_pointer, "\t");
		*current_command_count = 1;

	} else if (*current_command_count > 9) {

		fprintf(file_pointer, "\n");
		for (int i = 0; i < current_tabbing; i++) fprintf(file_pointer, "\t");
		*current_command_count = 1;

	} else {

		fprintf(file_pointer, " ");
		(*current_command_count)++;

	}
}