// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 02: Crivo de Eratosthenes"

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef enum Boolean {
	false,
	true
} bool;

List_t *list_primes(bool *primes, int total_numbers);

int main() {

	int primes_to_print;
	scanf("%d[^\n]", &primes_to_print);

	int primes_index[primes_to_print];

	int biggest_index = 0;

	// Scans
	for (int i = 0; i < primes_to_print; i++) {
		scanf("%d[^\n]", &(primes_index[i]));

		biggest_index = primes_index[i] > biggest_index ? primes_index[i] : biggest_index;
	}

	// Given the biggest possible prime to be 10,000 the highest prime between 2 and primes[index] is smaller than index * 10
	int total_numbers = biggest_index * 10;
	bool primes[total_numbers];

	// Eratosthenes Sieve for finding primes in range(2, n)
	for (int i = 2; i < total_numbers; i++) {
		primes[i] = true;
	}

	for (int i = 2; i < total_numbers; i++) {
		if (primes[i]) {
			for (int j = i; j * i < total_numbers; j++) {
				primes[j * i] = false;
			}
		}
	}

	// Inserts primes in order, thus making them accessible by prime index
	List_t *prime_numbers = list_primes(primes, total_numbers);

	for (int i = 0; i < primes_to_print; i++) {

		printf("%d ", search_list(prime_numbers, primes_index[i] - 1));

	}

	free_list(prime_numbers);

	return 0;
}

List_t *list_primes(bool *primes, int total_numbers) {

	List_t *list = create_list();

	for (int i = 2; i < total_numbers; i++) {
		if (primes[i]) {
			insert_list(list, i);
		}
	}

	return list;

}