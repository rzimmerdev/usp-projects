#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

typedef struct _QuadNode quad_node;
typedef struct _SkipList skip_list;

skip_list *create_sl(void *minus_infinity, int (*compare)(void *, void *), void (*remove)(void *));

quad_node *find_node(skip_list *list, void *value, int get_parent);
void *get_value(quad_node *node);

int add_node(skip_list *list, void *value);
int remove_node(skip_list *list, void *value);

#endif //WORD_FREQUENCY_LIST_H