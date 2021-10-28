// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 01: Palavras Mais Frequentes"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

typedef int bool;
enum { false, true };

// Structure for counting frequency for specific word
typedef struct dictionary {
	char *word;
	int frequency;
} Dict_t;

// Function for scanning one word, separated by spaces or \n from stdin
char *scan_word();

// Function for scanning and ordering array of dictionaries from stdin, using scan_word until \n
Dict_t *scan_dict();

// Print array of dictionaries, given total amount of elements to print (must be smaller than dict total elements)
void print_dict(Dict_t *dictionary, int total);

// Function for ordering array of dictionaries by frequency and alphabetically by word.
void order_dict(Dict_t *dictionary, int current_size);

int main() {

	Queue_t *queue = create_queue();
	do {
		// Scan dictionary, as well as send to queue for printing in order added
		int *current_size = (int *) malloc(1 * sizeof(int));

		Dict_t *current_dict = scan_dict(current_size);

		// Keep adding dictionary pointer, total dictionaries to print count, and current size to queue until reaching EOF
		if (*current_size != 0) {
			int *total_to_print = malloc(sizeof(int));
			scanf("%d", total_to_print);

			if (*total_to_print > *current_size) {
				*total_to_print = *current_size;
			}

			insert_queue(queue, current_dict);
			insert_queue(queue, total_to_print);
			insert_queue(queue, current_size);
		} else {
			free(current_size);
		}

		char last_char = (char) getchar();

		if (last_char != '\n' && last_char != '\r') {
			ungetc(last_char, stdin);
		}

	} while (!feof(stdin));

	// Print dictionaries in order by using queue
	// In essence, using the queue was not necessary, as printing could be done right after scanning
	// But a queue was added to preserve console log as well as
	// printing only after all calculations-> counting frequency and ordering had been made
	while (get_size(queue) > 0) {

		Dict_t *current_dict = (Dict_t *) pop_queue(queue);
		int *total_to_print = (int *) pop_queue(queue);
		int *current_size = (int *) pop_queue(queue);

		print_dict(current_dict, *total_to_print); if (get_size(queue) != 0) printf("\n");

		for (int i = 0; i < *current_size; i++) {
			free(current_dict[i].word);
		}

		free(current_size);
		free(total_to_print);
		free(current_dict);
	} free(queue);

	return 0;
}

char *scan_word() {

	int size = 0;
	char *str = malloc(0 * sizeof(char));
	char current_char;
	scanf("%c", &current_char);
	while (current_char != ' ' && current_char != '\n' && current_char != '\r') {
		str = realloc(str, ++(size) * sizeof(char));
		str[(size) - 1] = current_char;
		scanf("%c", &current_char);
	}
	if (size != 0) {
		ungetc(current_char, stdin);
		str = realloc(str, (size) + 1 * sizeof(char));
		str[(size)] = '\0';
		return str;
	} else if (current_char == '\n' || current_char == '\r') {
		return "\n";
	} else {
		return scan_word();
	}
}

void print_dict(Dict_t *dictionary, int total) {
	for (int i = 0; i < total; i++) {
		printf("%s %d\n", dictionary[i].word, dictionary[i].frequency);
	}
}

void order_dict(Dict_t *dictionary, int current_size) {

	// First, order dictionary by frequency size using insertion sort
	for (int i = 1; i < current_size; i++) {

		Dict_t current_values = dictionary[i];
		int j = i - 1;

		while (j >= 0 && current_values.frequency > dictionary[j].frequency) {
			dictionary[j + 1] = dictionary[j];
			j--;
		} dictionary[j + 1] = current_values;
	}

	// Then, still respecting order by frequency, order alphabetically using insertion sort
	for (int i = 1; i < current_size; i++) {

		Dict_t current_values = dictionary[i];
		int j = i - 1;

		while (j >= 0 && (current_values.frequency == dictionary[j].frequency && strcmp(current_values.word, dictionary[j].word) < 0)) {
			dictionary[j + 1] = dictionary[j];
			j--;
		} dictionary[j + 1] = current_values;
	}
}

Dict_t *scan_dict(int *size) {

	// Word scanned from stdin to evaluate presence in dictionary array, for counting frequency
	char *current_word = scan_word();

	int current_size = 0;
	Dict_t *current_dict = malloc(current_size * sizeof(Dict_t));

	while (strcmp(current_word, "\n") != 0 && strcmp(current_word, "\r") != 0 && strcmp(current_word, "\r\n") != 0) {
		bool found_word = false;
		int word_index;

		// Search if word is already present in dictionary
		for (int i = 0; i < current_size; i++) {
			if (strcmp(current_word, current_dict[i].word) == 0) {
				found_word = true;
				word_index = i;
			}
		}

		// If word is present, clear current scan and increment frequency
		if (found_word) {
			free(current_word);
			current_dict[word_index].frequency += 1;
		}
		// Else, add word pointer to new dictionary and initialize frequency
		else {
			current_dict = realloc(current_dict, ++(current_size) * sizeof(Dict_t));

			Dict_t new_dictionary = {.word = current_word, .frequency = 1};
			current_dict[current_size - 1] = new_dictionary;
		}

		current_word = scan_word();
	}

	// Set value of pointer parameter, so to send dictionary size to print function
	*size = current_size;

	if (current_size == 0) {
		free(current_dict);

		return NULL;
	} else {

		// Call function for ordering dictionary before returning
		order_dict(current_dict, current_size);

		return current_dict;
	}
}