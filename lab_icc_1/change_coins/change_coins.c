// Rafael Zimmer, 12542612

#include <stdio.h>

// Pass change_coins array value by reference
void calculate_change(int value, int *change_coins) {

	// Use modulo operator to consider only cents in same base -> if counting 50`s cents,
	// ignore value already discounted by 100`s cents.
	change_coins[0] = value / 100;
	change_coins[1] = ( (value - change_coins[0] * 100) ) / 50;
	change_coins[2] = ( (value - change_coins[1] * 50) % 100 ) / 25;
	change_coins[3] = ( (value - change_coins[2] * 25) % 50 ) / 10;
	change_coins[4] = ( (value - change_coins[3] * 10) % 25 ) / 5;
	change_coins[5] = ( (value - change_coins[4] * 5) % 5 );
}

int main() {

	// Scan initial value to conver to change in coins
	int value;
	scanf("%d", &value);

	// Declare array to pass reference to variables to calculate_change function
	int change[6];
	calculate_change(value, change);

	printf("O valor consiste em %d moedas de 1 real\n", change[0]);
	printf("O valor consiste em %d moedas de 50 centavos\n", change[1]);
	printf("O valor consiste em %d moedas de 25 centavos\n", change[2]);
	printf("O valor consiste em %d moedas de 10 centavos\n", change[3]);
	printf("O valor consiste em %d moedas de 5 centavos\n", change[4]);
	printf("O valor consiste em %d moedas de 1 centavo\n", change[5]);

}