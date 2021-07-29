#include <stdio.h>

int main() {

	char mem[30000] = { 0 };
	int i = 0;

	/* Beginning of compiled code */

	mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++;

	while(mem[i]) {

		mem[i]--;

		i++;

		mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++;

		i--;

	}

	i++;

	mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++; mem[i]++;
	putchar(mem[i]);


	/* End of compiled code */

	printf("\n");
	for (int j = 0; j < 30000; j++) {
		if (mem[j] != 0) {
			printf("%d ", mem[j]);
		}
	}
	printf("\n");

}
