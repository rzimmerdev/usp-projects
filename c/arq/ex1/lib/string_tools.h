#include <stdio.h>

#ifndef ARQ_SCANNER_H
#define ARQ_SCANNER_H

char *scan_word();
void scan_fixed(char *word);

void read_fixed(char* word, int total_size, FILE *fp);

/*
 * Writes an entire string, separating filled string bytes by null terminating character
 * (\0), and filling remaining size (total_size - strlen) with $ character in given
 * file pointer.
 *
 * @params:
 *          char *field_pointer: Pointer to array of strings containing characters to be written.
 *          int total_size: Total size of fixed array of characters, as to fill remaining size
 *                          with $ (empty) character.
 *          FILE *fp: File pointer at specific offset to write sequence at.
 */
void write_fixed(char *field_pointer, int total_size, FILE *fp);

#endif //ARQ_SCANNER_H
