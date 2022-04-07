/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 10/11/2021
 *  Project for Algorithms and Data Structures - SCC0202, "Atividade 09: Grandes Números"
*/

#include <stdio.h>
#include <stdlib.h>

#include "lib/struct/linked_list.h"

/*
 *  Creates linked list and stores stdin characters as digits into new node.
 *  Additional features are saving first digit as negative in case number is negative,
 *  and ignoring leading zeroes while scanning.
 *
 *  @Returns:
 *          linked list containing node digits: linked_list *
 */
linked_list *scan_big_number() {

    linked_list *number = create_list();

    char current_char;
    scanf("%c", &current_char);
    int is_negative = 0;

    if (current_char == '-')
        is_negative = 1;

    else
        ungetc(current_char, stdin);

    int is_leading_zero = 0;

    while (scanf("%c", &current_char) != EOF && current_char != ' ' && current_char != '\n') {

        if (current_char != '0' && is_leading_zero == 0) {
            is_leading_zero = 1;
        }

        if (current_char != '\r' && is_leading_zero != 0) {

            int *current_digit = malloc(sizeof(int));
            *current_digit = current_char - '0';

            add_node(number, current_digit);
        }
    }

    if (is_negative == 1) {
        *(int *) (get_node_value(number->start)) = -1 * *(int *) (get_node_value(number->start));
    }

    return number;
}

/*
 *  Function to compare sequence of digits from initial nodes in linked lists,
 *  ignoring rest if the sequence differs at some point
 *
 *  @Returns:
 *          integer representing comparison between sequence of digits,
 *          1 if first sequence has bigger ints until position x,
 *          0 if both lists have same ints until end of one of the sequences
 *         -1 if second sequence has bigger ints until position x
 */
int compare_big_number_recursive(node *first_number_digit, node *second_number_digit) {

    int comparison = 0;

    // If not at end of the sequences, keep recursively comparing until comparison does not return equal
    if (get_node_next(first_number_digit) != NULL && get_node_next(second_number_digit) != NULL) {
        comparison = compare_big_number_recursive(get_node_next(first_number_digit), get_node_next(second_number_digit));
    }

    if (comparison == 0) {
        if (*(int *) get_node_value(first_number_digit) < *(int *) get_node_value(second_number_digit))
            return 1;

        else if (*(int *) get_node_value(first_number_digit) > *(int *) get_node_value(second_number_digit))
            return -1;

    }

    return comparison;
}

/*
 *  Function to compare two big numbers stored in linked lists,
 *  using compare_big_number_recursive function to compare two numbers with same digit length,
 *  and using basic comparison if the size of both lists differ
 *
 *  @Returns:
 *          1 if first number is bigger,
 *          0 if both numbers are equal,
 *         -1 if second number is bigger
 */
int compare_big_number(linked_list *first_number, linked_list *second_number) {

    // First compare signs of both numbers
    if (*(int *) get_node_value(first_number->start) >= 0 && *(int *) get_node_value(second_number->start) < 0)
        return 1;

    else if (*(int *) get_node_value(second_number->start) >= 0 && *(int *) get_node_value(first_number->start) < 0)
        return -1;

    // If sign is equal, compare sizes
    else {
        if (first_number->size != second_number->size) {
            return *(int *) (get_node_value(first_number->start)) > 0 ?
                (first_number->size > second_number->size) * 2 - 1 : (first_number->size < second_number->size) * 2 - 1;
        }

        // If size is equal, and sign is equal, compare digit by digit until different digit is found
        else {
            return compare_big_number_recursive(first_number->start, second_number->start);
        }
    }
}

/*
 *  Sums two big numbers into resulting linked_list array
 *
 *  @Input:
 *
 *  @Returns:
 *          1 if first number is bigger,
 *          0 if both numbers are equal,
 *         -1 if second number is bigger
 */
linked_list *sum_numbers(linked_list *first_number, linked_list *second_number) {

    linked_list *temporary = create_list();

    // Start operation from end of linked_list
    node *first_number_digit = first_number->end;
    node *second_number_digit = second_number->end;

    int increment = 0;

    int final_size = first_number->size > second_number->size ? first_number->size : second_number->size;

    // Decide if sum of digits should increment next decimal place,
    // and insert current digit sum mod 10 into temporary array
    for (int i = 0; i < final_size; i++) {

        int current_digit = increment;

        if (first_number_digit != NULL) {

            current_digit += *(int *) get_node_value(first_number_digit);
            first_number_digit = get_node_previous(first_number_digit);
        }

        if (second_number_digit != NULL) {

            current_digit += *(int *) get_node_value(second_number_digit);
            second_number_digit = get_node_previous(second_number_digit);
        }

        increment = current_digit / 10;
        current_digit = current_digit % 10;

        int *resulting_digit = malloc(sizeof(int));
        *resulting_digit = current_digit;

        add_node(temporary, resulting_digit);
    }

    // Decide if last digit sum overflows original biggest linked_list size
    if (increment == 1) {

        int *resulting_digit = malloc(sizeof(int));
        *resulting_digit = 1;

        add_node(temporary, resulting_digit);
        final_size += 1;
    }

    // Reverse temporary array into right digit order in result array
    linked_list *result = create_list();

    for (int i = 0; i < final_size; i++) {
        add_node(result, pop_end(temporary));
    }

    free(temporary);

    return result;
}

// Print sequence of digits stored in linked_list nodes
void print_number(linked_list *number) {

    node *current_digit = number->start;

    while (current_digit != NULL) {

        printf("%d", *(int *) get_node_value(current_digit));
        current_digit = get_node_next(current_digit);

    } printf("\n");
}