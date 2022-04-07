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
char *scan_word(int *size_pointer);


/*
 *  Replaces all occurrences of substring in string with substitute value
 *
 *  @Input:
 *         destination string: char* string,
 *         substring to replace: char *substring,
 *         value to insert in place: char *substitute
*/
void replace_string(char *string, char *substring, char *substitute)


#endif
