#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

typedef struct node Node_t;
typedef struct linked_list LinkedList_t;

void *create_list();
int get_size(LinkedList_t *list);

void add_node(LinkedList_t *list, void *value);
void free_nodes(Node_t *node);

void *get_node_value(Node_t *node);
Node_t *get_node_next(Node_t *node);

void remove_node(LinkedList_t *list, int depth);
Node_t *search_node(LinkedList_t *list, int depth);
void swap_nodes(Node_t *first, Node_t *second);

#endif //WORD_FREQUENCY_LIST_H