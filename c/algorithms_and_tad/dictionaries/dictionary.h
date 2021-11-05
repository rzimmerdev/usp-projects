#ifndef USP_PROJECTS_DICTIONARY_H
#define USP_PROJECTS_DICTIONARY_H

skip_list *create_dictionary();

int add_entry(skip_list *dictionary, char *word, char *description);
int remove_entry(skip_list *dictionary, char *word);

char *get_description(skip_list *dictionary, char *word);

#endif //USP_PROJECTS_DICTIONARY_H
