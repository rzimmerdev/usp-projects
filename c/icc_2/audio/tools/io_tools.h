#ifndef WORD_REPLACE_STRING_REPLACER_H
#define WORD_REPLACE_STRING_REPLACER_H

// Scans a single line from stdin, ending in \n or \r characters, as well as returning allocated pointer
char *scan_line();

// Reads a .wav file as a binary file, given file_name string and returns array of unsigned char values
unsigned char *read_wav(char *file_name, int *total_size);

// Creates new file and writes total size of data content to new file, while copying header from original file
void write_wav(char *original_file_name, char *new_file_name, unsigned char *data, int size);

#endif
