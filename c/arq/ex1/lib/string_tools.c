#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *scan_word() {

    int size = 0;
    char *word = malloc(size * sizeof(char));
    char current_char;

    while (scanf("%c", &current_char) == 1 && current_char != '\n' && current_char != ' ') {
        if (current_char != '\r') {
            word = realloc(word, ++size * sizeof(char));
            word[size - 1] = current_char;
        }
    }

    word = realloc(word, (size + 1) * sizeof(char));
    word[size] = '\0';
    return word;
}

void scan_fixed(char* word){

    char current_char;
    int size = 0;
    while (scanf("%c", &current_char) == 1 && current_char != '\n' && current_char != ' ') {
        if (current_char != '\r') {
           word[size++] = current_char;
        }
    }
    word[size] = '\0';
}


void read_fixed(char* word, int total_size, FILE *fp) {

    char current_char;
    int size = 0;

    while (fscanf(fp, "%c", &current_char) == 1 && current_char != '\0') {
        if (current_char != '\r') {
            word[size++] = current_char;
        }
    }
    word[size] = '\0';

    for (int i = size; i < total_size - 1; i++) {

        getc(fp);
    }
}


void write_fixed(char *field_pointer, int total_size, FILE *fp) {

    int str_len = strlen(field_pointer) + 1;

    for (int i = str_len; i < total_size; i++) {

        field_pointer[i] = '$';
    }

    fwrite(field_pointer, sizeof(char), total_size, fp);
}