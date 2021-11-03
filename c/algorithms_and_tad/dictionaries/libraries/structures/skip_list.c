/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021, 13:18
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdlib.h>
#include <time.h>

typedef struct _QuadNode {

    void *value;

    struct _QuadNode *head;
    struct _QuadNode *child;

    struct _QuadNode *previous;
    struct _QuadNode *next;

} quad_node;

typedef struct _SkipList {

    quad_node *head;
    int height;
    int size;

    void (*compare)(void *, void*);

} skip_list;

quad_node *create_quad_node(void *value, quad_node *head, quad_node *previous) {

    quad_node *node = malloc(sizeof(quad_node));

    node->head = head;
    node->previous = previous;

    srand(time(NULL));

    return node;
}


skip_list *create_sl(void *minus_infinity, void (*compare)(void *, void *)) {

    skip_list *sl = malloc(sizeof(skip_list));
    sl->height = 0;
    sl->size = 0;

    sl->compare = compare;

    quad_node *head = create_quad_node(minus_infinity, NULL, NULL);

    return sl;
}

quad_node *find_node(skip_list *list, void *value) {

    quad_node *current = malloc(sizeof(quad_node));

    return current;
}

void add_node(skip_list *list, void *value) {

    quad_node *parent = find_node(list, value);
    quad_node *current = malloc(sizeof(quad_node));
}