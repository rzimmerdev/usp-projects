/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021, 13:18
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libraries/structures/skip_list.h"

typedef struct Entry {

    char *word;
    char *description;

} entry;


int compare_words(void *first_entry, void *second_entry) {

    if (second_entry == NULL) {
        return 1;
    }

    return strcmp(((entry *) first_entry)->word, ((entry *) second_entry)->word);
}

void free_entry(void *to_remove) {
    if ((entry *) to_remove != NULL) {
        free(((entry *) to_remove)->word);

        char *description = ((entry *) to_remove)->description;
        if (description) {
            free(description);
        }

        free((entry *) to_remove);
    }
}

skip_list *create_dictionary() {

    // Since smallest word is "A", which in the ASCII table represents the number 41, any character
    // smaller than 'A' is equivalent to negative infinite if comparing only alphabet characters

    entry *new_entry = calloc(1, sizeof(entry));

    char *minus_inf = calloc(2, sizeof(char));
    minus_inf[0] = '@';

    new_entry->word = minus_inf;

    skip_list *dictionary = create_sl(new_entry, compare_words, free_entry);

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

    quad_node *found = find_node(dictionary, placeholder_entry);
    entry *value;

    char *description = NULL;
    if (compare_words(placeholder_entry, get_value(found)) == 0) {

        free(placeholder_entry);

        value = (entry *) get_value(found);
        description = value->description;
        return description;
    }

    free(placeholder_entry);
    return NULL;
}

int replace_description(skip_list *dictionary, char *word, char *new_description) {

    entry *placeholder_entry = malloc(sizeof(entry));
    placeholder_entry->word = word;

    entry *found_entry = ((entry *) get_value(find_node(dictionary, placeholder_entry)));

    free(placeholder_entry);

    if (strcmp(found_entry->word, word) == 0) {
        free(found_entry->description);
        found_entry->description = new_description;
        return 1;
    } else {
        return -1;
    }
}

int remove_entry(skip_list *dictionary, char *word) {

    entry *placeholder_entry = malloc(sizeof(entry));
    placeholder_entry->word = word;

    int out = remove_node(dictionary, placeholder_entry);

    free(placeholder_entry);

    return out;
}

int compare_prefix(void *prefix, void *string) {

    int size = strlen(((entry *) prefix)->word);

    return strncmp(((entry *) prefix)->word, ((entry *) string)->word, size);
}

int print_entries(skip_list *dictionary, char *prefix) {

    entry *placeholder_entry = malloc(sizeof(entry));
    placeholder_entry->word = prefix;

    quad_node *current = find_node(dictionary, placeholder_entry);

    if (current == NULL || compare_prefix(placeholder_entry, (entry *) get_value(current)) != 0) {
        free(placeholder_entry);
        return -1;
    }

    while (current != NULL && compare_prefix(placeholder_entry, get_value(current)) == 0) {
        printf("%s %s\n", ((entry *) get_value(current))->word, ((entry *) get_value(current))->description);
        current = get_previous(current);
    }

    free(placeholder_entry);
    return 1;
}

void free_dictionary(skip_list *dictionary) {

}