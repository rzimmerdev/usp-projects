#ifndef WORD_STRING_TOOLS_H
#define WORD_STRING_TOOLS_H


/*
 *  Scans and stores characters in string until '\n' or '\r' character from STDIN,
 *  and returns allocated string
 *
 *  @Returns:
 *           string array pointer: char*;
*/
char *scan_line();


/*
 *  Scans and stores a single word in string from STDIN,
 *  separated by ' ' (space) or new-line characters
 *
 *  @Returns:
 *            string array pointer: char*;
*/
char *scan_word();

char *file_scan_word(FILE *file_pointer);


#endif
