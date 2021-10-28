#ifndef WORD_REPLACE_STRING_REPLACER_H
#define WORD_REPLACE_STRING_REPLACER_H

// Replaces all occurences of a substring inside a string
// with input substitute string
void replace_string(char *string, char *substring, char *substitute);

// Scans a single line from stdin, ending in \n or \r characters, as well as returning allocated pointer
char *scan_line(int *size_pointer);

#endif
