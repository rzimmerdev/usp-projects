// Rafael Zimmer, nUsp 12542612
// Project for Discrete Mathematics - SMA0180-201, "Trabalho 05: Inverso de um inteiro"
//
// Codigo fonte do executavel para achar o inverso de um número B no conjunto de inteiros de um número A.
//
// Ex: inverse 169 144
//
// A chamada acima do executavel ira calcular o inverso de 144 em Z_{169}.
// E ira printar o resultado, assim como as etapas mais importantes do Algoritmo de Euclides Extendido no Console.

#include <stdio.h>
#include <stdlib.h>

#define input_size long int

input_size gcd_extended(input_size divisor, input_size dividend, input_size *i, input_size *j, int spacing);

int main(int argc, char *argv[]) {

	// Verificar se os argumentos de chamada do executável são válidos
	if (argc != 3) {
		printf("\nNúmero de argumentos inválidos!\n");
		printf("Chamada correta: \n");
		printf("./main valor_anel_comutativo valor_do_conjunto\n\n");
		return -1;
	}

	// Instancia variáveis a partir dos argumentos passados no Console
	input_size commutative_ring = strtol(argv[1], NULL, 10);
    input_size value = strtol(argv[2], NULL, 10);

	printf("\n---------------------------\n\n");
	printf("Chamada do Algoritmo de Euclides:\n\n");

	// Chamada do algoritmo de Euclides Extendido
	int current_iteration = 0;
	input_size i;
	input_size j;

	int gcd_result = gcd_extended(commutative_ring, value, &i, &j, current_iteration);

	// Avalia o resultado da chamada do algoritmo (se o MCD for 1, o valor é invertível e seu inverso é j)
	printf("\n---------------------------\n");
	if (gcd_result == 1) {
		printf("\no inverso de %ld em Z_%ld é %ld\n\n", value, commutative_ring, j);
	}

	// Caso contrário (MCD != 1), o valor não é invertível no anel em questão
	else {
		printf("\n%ld em Z_%ld não é inversível!\n\n", value, commutative_ring);
	}
}

// Euclides Algorithm (Extendido)
//
// Função recursiva que implementa o algoritmo de Euclides para obter o Maior Divisor Comum entre dois inteiros.
// Tem como entrada um valor para o dividendo, para o divisor e um inteiro chamado spacing que conta
// a quantidade de iterações da função recursiva, o que permite mostrar no console o número da iteração,
// assim como formatar com espaços cada saída. A versão extendida recebe também dois endereços pra variáveis, na forma
// dividend * i + divisor * j = 1;
//
// Sendo assim, obtemos o valor do inverso do divisor, sendo seu valor guardado na variavel j.
input_size gcd_extended(input_size divisor, input_size dividend,
				 		input_size *i, input_size *j, int spacing)
{
	for (int i = 0; i < spacing; i++) { printf(" "); }
	if (spacing != 0) {
		printf("└- Iteração %d -> Dividendo: %ld; Divisor: %ld\n", spacing, dividend, divisor);
	}

	input_size i_temporary, j_temporary;

	// Caso base da função recursiva,
	// retorna o último dividendo quando o divisor é 0 (Resto anterior foi 0)
	if (divisor == 0) {
		*i = 0;
		*j = 1;

		for (int i = 0; i < spacing; i++) { printf(" "); }
		printf(" => Maior divisor em comum: %ld\n", dividend);
		return dividend;
	}

	input_size modulo = dividend % divisor;
	input_size recursive_extended = gcd_extended(modulo, divisor, &i_temporary, &j_temporary, spacing + 1);

	// Pela equação dividendo * i + divisor * j = 1,
	// é possível atribuir a i e j valores a medida que
	// a função recursiva é retornada
	*i = j_temporary - (dividend / divisor) * i_temporary;
	*j = i_temporary;

	return recursive_extended;
}
