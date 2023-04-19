// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 08: Polinomios"
#include <stdio.h>
#include <stdlib.h>
#include "structures/linked_list.h"

linked_list *scan_polynomial(int *coefficients_amount);
void print_polynomial(linked_list *list);
void sum_polynomials(linked_list *result, Node_t **addends, int total_addends, int max_coefficients);

int main() {

	int total_cases;
	scanf("%d ", &total_cases);

	// Iterate over each individual test case
	for (int test_case = 0; test_case < total_cases; test_case++) {

		int total_polynomials;
		scanf("%d ", &total_polynomials);

		linked_list **polynomials_list = malloc(total_polynomials * sizeof_linked_list());
		int max_coefficients = 0;

		linked_list *result = create_list();
		Node_t **pointers = malloc(total_polynomials * sizeof_node());

		// For each test case, save list of polynomials, as well as pointer to head of list,
		// and result polynomial to add each individual coefficient to
		for (int i = 0; i < total_polynomials; i++) {

			int current_coefficients;
			polynomials_list[i] = scan_polynomial(&current_coefficients);

			pointers[i] = get_start(polynomials_list[i]);
			max_coefficients = max_coefficients < current_coefficients ? current_coefficients : max_coefficients;

		}

		sum_polynomials(result, pointers, total_polynomials, max_coefficients);

		for (int i = 0; i < total_polynomials; i++) {
			free_list(polynomials_list[i]);
		}

		// Print result and free auxiliary pointers, as well as result and polynomials list
		print_polynomial(result);

		free(polynomials_list);
		free_list(result);
		free(pointers);

	}

	return 0;
}

// Scans a single line containing a polynomial vector closed by parenthesis,
// storing each polynomial coefficient in linked list, and returns allocated linked list
linked_list *scan_polynomial(int *coefficients_amount) {

	linked_list *polynomial = create_list();

	char current_char;
	scanf("%c", &current_char);

	*coefficients_amount = 0;
	while (current_char != ')') {

		int *current_value = malloc(sizeof(int));
		scanf("%d", current_value);
		add_node(polynomial, current_value);
		scanf("%c", &current_char);
		(*coefficients_amount)++;
	} scanf("%*c ");

	return polynomial;
}

// Sums into result linked list values of each addend at correct index,
// and iterate over each addend until linked list reaches end (Addend pointer becomes null)
void sum_polynomials(linked_list *result, Node_t **addends, int total_addends, int max_coefficients) {
	for (int c = 0; c < max_coefficients; c++) {

		int *current_sum = malloc(sizeof(int));
		*current_sum = 0;

		for (int i = 0; i < total_addends; i++) {
			if (addends[i] != NULL) {
				*current_sum += *(int *) get_node_value(addends[i]);
				addends[i] = get_node_next(addends[i]);
				}
		}

		add_node(result, current_sum);
	}
}

// Print formatted polynomial based on linked list, in added order and encapsulated with parenthesis
void print_polynomial(linked_list *list) {
	printf("(");

	Node_t *current = get_start(list);

	for (int i = 0; i < get_size(list) - 1; i++) {
		printf("%d,", *(int *) get_node_value(current));
		current = get_node_next(current);
	}
	printf("%d)\n", *(int *) get_node_value(current));

}