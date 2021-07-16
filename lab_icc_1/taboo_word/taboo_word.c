#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char taboo_word[20];
	scanf("%s\n", taboo_word);

	char *phrase = calloc(0, sizeof(char));

	printf("%d", strcmp(taboo_word, "demacia"));
	free(phrase);
	return 0;
}
