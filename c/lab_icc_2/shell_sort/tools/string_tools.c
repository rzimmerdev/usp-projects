#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *scan_word() {

	int size = 0;
	char *str = malloc(size * sizeof(char));
	char current_char;
	while (scanf("%c", &current_char) == 1 && current_char != ' ' && current_char != '\n' && current_char != '\r') {
		str = realloc(str, ++size * sizeof(char));
		str[size - 1] = current_char;
	}
	if (size != 0) {
		str = realloc(str, (size + 1) * sizeof(char));
		str[size] = '\0';
		return str;
	} else {
		free(str);
		return "\0";
	}
}