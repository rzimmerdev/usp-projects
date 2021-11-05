/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021, 13:18
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdlib.h>
#include <string.h>

#include "libraries/structures/skip_list.h"

typedef struct _Entry {

    char *word;
    char *description;

} entry;


int compare_words(void *first_entry, void *second_entry) {

    return strcmp(((entry *) first_entry)->word, ((entry *) second_entry)->word);
}

void free_entry(void *to_remove) {
    free(((entry *) to_remove)->word);
    free(((entry *) to_remove)->description);
    free((entry *) to_remove);
}

skip_list *create_dictionary() {

    // Since smallest word is "A", which in the ASCII table represents the number 41, any character
    // smaller than 'A' is equivalent to negative infinite if comparing only alphabet characters
    char *minus_inf = malloc(sizeof(char));
    minus_inf[0] = '@';

    skip_list *dictionary = create_sl(minus_inf, compare_words, free_entry);

    return dictionary;
}

int add_entry(skip_list *dictionary, char *word, char *description) {

    entry *new_entry = malloc(sizeof(entry));
    new_entry->word = word;
    new_entry->description = description;

    int out = add_node(dictionary, new_entry);
    return out;
}

char *get_description(skip_list *dictionary, char *word) {

    entry *placeholder_entry = malloc(sizeof(entry));
    placeholder_entry->word = word;

    char *description = ((entry *) get_value(find_node(dictionary, placeholder_entry, 0)))->description;
    free(placeholder_entry);
    return description;
}

int remove_entry(skip_list *dictionary, char *word) {

    entry *placeholder_entry = malloc(sizeof(entry));
    placeholder_entry->word = word;

    int out = remove_node(dictionary, placeholder_entry);

    free(placeholder_entry);

    return out;
}

int compare_prefix(void *prefix, void *substring) {

    int size = sizeof((char *) prefix);

    return strncmp((char *) prefix, (char *) substring, size);jytrex
}

int print_entries(skip_list *dictionary, char *prefix) {


}

void free_dictionary(skip_list *dictionary) {

}