/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021, 13:18
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct QuadNode {

    void *value;

    struct QuadNode *above;
    struct QuadNode *below;

    struct QuadNode *previous;
    struct QuadNode *next;

} quad_node;

typedef struct SkipList {

    quad_node *head;
    int height;

    int (*compare)(void *, void*);
    void (*delete)(void *);

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


skip_list *create_sl(void *minus_infinity, int (*compare)(void *, void *), void (*delete)(void *)) {

    skip_list *sl = malloc(sizeof(skip_list));
    sl->height = 1;

    sl->compare = compare;
    sl->delete = delete;

    quad_node *head = create_quad_node(minus_infinity, NULL, NULL);

    sl->head = head;

    return sl;
}

quad_node *find_node(skip_list *list, void *value) {

    quad_node *current = list->head;

    while (current != NULL && current->next != NULL) {

        int comparison = list->compare(current->next->value, value);

        if (comparison == 0) {
            current = current->next;
            while (current->below != NULL) {

                current = current->below;
            }
            return current;
        }

        else if (comparison < 0) {

            current = current->next;
        }

        else if (comparison > 0) {
            if (current->below != NULL) {

                current = current->below;
            } else {
                return current;
            }
        }
    }

    return current;
}

quad_node **find_levels(skip_list *list, void *value) {

    quad_node **levels = malloc(sizeof(quad_node *) * list->height);
    int i = list->height;
    quad_node *current = list->head;

    while (current != NULL) {

        int comparison;

        if (current->next == NULL) {
            comparison = list->compare(NULL, value);
        } else {
            comparison = list->compare(current->next->value, value);
        }

        if (comparison == 0) {
            current = current->next;
            while (current->below != NULL) {

                current = current->below;
            }
            return levels;
        }

        else if (comparison < 0) {

            current = current->next;
        }

        else if (comparison > 0) {
            if (current->below != NULL) {
                levels[--i] = current;
                current = current->below;
            } else {
                return levels;
            }
        }
    }

    return levels;
}


quad_node *get_next(quad_node *node) {
    return node->next;
}

quad_node *get_previous(quad_node *node) {
    return node->previous;
}

void *get_value(quad_node *node) {
    return node->value;
}

int add_node(skip_list *list, void *value) {
    quad_node *parent = find_node(list, value);

    if (parent == NULL || parent->value == NULL) {
        return -1;
    } else if (parent->value != list->head->value && list->compare(parent->value, value) == 0) {
        return -1;
    }

    quad_node *node = create_quad_node(value, NULL, parent);
    node->next = parent->next;
    if (parent->next != NULL) {
        parent->next->previous = node;
    }
    parent->next = node;

    quad_node *previous = node;

    while (rand()%2 == 1) { // NOLINT(cert-msc30-c, cert-msc50-cpp)

        quad_node *above = create_quad_node(value, NULL, parent);
        above->below = previous;

        previous = above;
    }

    return 1;
}

int remove_node(skip_list *list, void *value) {

    if (list->head->next == NULL) {
        return -1;
    }

    quad_node *found = find_node(list, value);

    if (found != NULL && list->compare(value, found->value) == 0) {

        found->previous->next = found->next;
        found->next->previous = found->previous;

        list->delete(found->value);
        free(found);

        return 1;
    }

    return -1;
}