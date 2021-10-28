#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *scan_line(int *size_pointer) {

	int size = 0;
	char *str = malloc(100 * sizeof(char));
	char current_char;
	while (scanf("%c", &current_char) == 1 && current_char != '\n' && current_char != '\r') {
		str[size++] = current_char;
	}
	if (size != 0) {
		str = realloc(str, (size + 1) * sizeof(char));
		str[size] = '\0';
		if (size_pointer != NULL) *size_pointer = size;
		return str;
	} else {
		free(str);
		return "\0";
	}
}

void replace_string(char *string, char *substring, char *substitute) {

	int string_size = strlen(string);
	int substring_size = strlen(substring);
	int substitute_size = strlen(substitute);

	char *pointer = strstr(string, substring);

	while (pointer != NULL) {

		// If substring size is bigger then substitute size, text should be left-shifted to
		// match final substitute position, as well as reducing string size and inserting content into position
		if (substring_size > substitute_size) {

			int offset = string_size - substring_size  - (int) (pointer - string);
			memmove(pointer + substitute_size, pointer + substring_size, offset);
			memcpy(pointer, substitute, substitute_size);
			string_size -= (substring_size - substitute_size);
			string = realloc(string, (string_size + 1) * sizeof(char));
			string[string_size] = '\0';

		}

		// If substring is bigger, should first expand string, then reset pointer, and right-shift content to match
		// final position of substitute string, and finally copy content to pointer position
		else if (substring_size < substitute_size) {

			int offset = string_size - substring_size  - (int) (pointer - string);
			string_size += substitute_size - substring_size;
			string = realloc(string, (string_size + 1) * sizeof(char));
			string[string_size] = '\0';
			char *pointer = strstr(string, substring);
			memmove(pointer + substitute_size, pointer + substring_size, offset);
			memcpy(pointer, substitute, substitute_size);

		}

		// If both sizes are equall, simply copying content of substitute into pointer position is enough
		else {
			memcpy(pointer, substitute, substitute_size);
		}
		pointer = strstr(string, substring);
	}
}