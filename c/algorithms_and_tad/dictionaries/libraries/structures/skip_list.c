/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 02/10/2021
 *  Advanced Data Structure library for creating Skip Lists with generic attributes
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct QuadNode {

    void *value;

    struct QuadNode *below;
    struct QuadNode *above;

    struct QuadNode *previous;
    struct QuadNode *next;

} quad_node;

typedef struct SkipList {

    quad_node *head;
    int height;

    int (*compare)(void *, void*);
    void (*delete)(void *);

} skip_list;

quad_node *create_quad_node(void *value, quad_node *below, quad_node *previous) {

    quad_node *node = malloc(sizeof(quad_node));
    node->value = value;

    node->previous = previous;
    node->next = NULL;

    node->above = NULL;
    node->below = below;

    return node;
}


skip_list *create_sl(void *minus_infinity, int (*compare)(void *, void *), void (*delete)(void *)) {

    skip_list *sl = malloc(sizeof(skip_list));
    sl->height = 1;

    sl->compare = compare;
    sl->delete = delete;

    quad_node *head = create_quad_node(minus_infinity, NULL, NULL);

    sl->head = head;

    return sl;
}

quad_node **find_levels(skip_list *list, void *value) {

    quad_node **levels = calloc(list->height, sizeof(quad_node *));

    int i = list->height;
    quad_node *current = list->head;

    while (current != NULL) {

        int comparison;

        if (current->next == NULL) {
            comparison = list->compare(value, NULL);
        } else {
            comparison = list->compare(value, current->next->value);
        }

        // If comparison is negative, go to next, until found or next is bigger
        if (comparison < 0) {

            current = current->next;
        }

        // If comparison is positive, next value is bigger than searched for value,
        // thus, search should continue on the level below
        else if (comparison > 0) {

            levels[--i] = current;
            current = current->below;
        }

        // If value has been found, traverse until lowest level has been reached (null node found)
        else {

            current = current->next;
            while (current) {

                levels[--i] = current;
                current = current->below;
            }
        }
    }

    return levels;
}

// Returns first level value of level search function
quad_node *find_node(skip_list *list, void *value) {

    quad_node **found = find_levels(list, value);

    quad_node *node = found[0];
    free(found);
    return node;
}

quad_node *get_previous(quad_node *node) {
    return node->previous;
}

quad_node *get_next(quad_node *node) {
    return node->next;
}

void *get_value(quad_node *node) {
    return node->value;
}

// Uses find_levels function to find parent in each level for new node pillar
// and uses random probabilistic comparison to determine if node value should be added
// in upper level
int add_node(skip_list *list, void *value) {
    quad_node **parents = find_levels(list, value);

    if (parents) {
        if (list->compare(value, parents[0]->value) == 0) {
            return -1;
        } else {

            int current_level = 0;

            quad_node *node = NULL;

            while(rand() % 2 != 1 || current_level == 0) {
                quad_node *below = node;
                if (current_level < list->height) {

                    node = create_quad_node(value, below, parents[current_level]);

                } else {

                    quad_node *head = create_quad_node(list->head->value, list->head, NULL);
                    head->below->above = head;
                    list->head = head;
                    node = create_quad_node(value, below, head);
                    list->height++;
                }

                if (below) below->above = node;

                node->next = node->previous->next;

                if (node->next) {
                    node->next->previous = node;
                } else {
                    node->next = NULL;
                }

                node->previous->next = node;

                current_level++;
            }
        }
    }

    free(parents);
    return 1;
}

int remove_node(skip_list *list, void *value) {

    quad_node *node = find_node(list, value);

    if (list->compare(value, node->value) != 0) {
        return -1;
    }

    list->delete(node->value);

    while (node) {

        quad_node *temp = node->above;

        if (node->next) {
            node->next->previous = node->previous;
        }

        node->previous->next = node->next;

        free(node);
        node = temp;
    }

    return 1;
}

// Key strategy is to iterate through list through bottom nodes, as to allow for single freeing
// of value, as well as being able to iterate upwards without needing to instantiate more memory
// for recursion alternative to free each node pillar
void free_list(skip_list *list) {

    quad_node *bottom = list->head;

    while (bottom->below) {
        bottom = bottom->below;
    }

    while (bottom) {
        quad_node *temp;
        quad_node *current = bottom->above;
        while(current) {
            temp = current->above;
            free(current);
            current = temp;
        }
        temp = bottom->next;
        list->delete(bottom->value);

        free(bottom);
        bottom = temp;
    }

    free(list);
}