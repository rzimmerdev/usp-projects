// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 03: Substituir String"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "string_tools.h"

int main() {

	Queue_t *queue = create_queue();
	char *line;

	// Scan multiple lines and insert formatted string into queue, so as to allow any future operations on string.
	// Queue was used to demonstrate the use of first-in, first-out implementation, but since the only operation
	// to be performed on formatted string was printing it, not much potential could be shown
	do {
		int line_size;
		line = scan_line(&line_size);

		if (line[0] != '\0') {

			int substring_size = 0, substitute_size;

			char *substring = scan_line(&substring_size);
			char *substitute = scan_line(&substitute_size);

			// Calls string_tools replace_string function, and stores it into queue, for later use,
			// preserving insert sequence order
			replace_string(line, substring, substitute);
			free(substring);
			free(substitute);
			insert_queue(queue, line);
		}

	} while (line[0] != '\0');

	int queue_size = get_size(queue);
	for (int i = 0; i < queue_size; i++) {
		line = (char *) pop_queue(queue);
		printf("%s\n", line);
		free(line);
	}

	free_queue(queue);
	return 0;
}