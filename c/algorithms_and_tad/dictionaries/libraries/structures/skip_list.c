/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021, 13:18
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct _QuadNode {

    void *value;

    struct _QuadNode *above;
    struct _QuadNode *below;

    struct _QuadNode *previous;
    struct _QuadNode *next;

} quad_node;

typedef struct _SkipList {

    quad_node *head;
    int height;
    int size;

    int (*compare)(void *, void*);
    void (*remove)(void *);

} skip_list;

quad_node *create_quad_node(void *value, quad_node *above, quad_node *previous) {

    quad_node *node = malloc(sizeof(quad_node));
    node->value = value;

    node->above = above;
    node->previous = previous;

    node->next = NULL;
    node->below = NULL;

    return node;
}


skip_list *create_sl(void *minus_infinity, int (*compare)(void *, void *), void (*remove)(void *)) {

    skip_list *sl = malloc(sizeof(skip_list));
    sl->height = 0;
    sl->size = 0;

    sl->compare = compare;
    sl->remove = remove;

    quad_node *head = create_quad_node(minus_infinity, NULL, NULL);

    sl->head = head;

    return sl;
}

quad_node *find_node(skip_list *list, void *value, int get_parent) {

    quad_node *current = list->head;

    while (current != NULL && current->next != NULL) {

        int comparison = list->compare(value, current->next->value);

        if (comparison == 0) {
            if (get_parent != 1) {
                current = current->next;
                while (current->below != NULL) {

                    current = current->below;
                }
            } else {
                break;
            }
        }

        else if (comparison < 0) {

            current = current->next;
        }

        else {
            if (current->below != NULL) {

                current = current->below;
            } else {
                break;
            }
        }
    }

    return current;
}

void *get_value(quad_node *node) {
    return node->value;
}

int add_node(skip_list *list, void *value) {
    quad_node *parent = list->head;

    if (parent->next != NULL) {
        parent = find_node(list, value, 1);
    }

    if (parent->next != NULL && list->compare(value, parent->next) == 0) {
        return -1;
    }

    quad_node *node = create_quad_node(value, NULL, parent);
    parent->next = node;

    return 1;
}

int remove_node(skip_list *list, void *value) {

    quad_node *parent = list->head;
    if (parent->next != NULL) {
        parent = find_node(list, value, 1);

        if (parent->next != NULL) {
            quad_node *next = parent->next->next;
            list->remove(parent->next->value);
            free(parent->next);
            parent->next = next;
        }  else return -1;
    } else return -1;

    return 1;
}
