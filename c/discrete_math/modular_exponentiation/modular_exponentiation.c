/******************************************************************************

    Trabalho 7
    Autor: Rafael Zimmer, nUsp: 12542612

    Trabalho feito para a Disciplina Matematica Discreta.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 8
#define INPUT_TYPE unsigned int

int modular_exponentiation(INPUT_TYPE base, INPUT_TYPE exponent, INPUT_TYPE modulo) {

    // Definir o fator inicial sendo igual a base a ser exponenciada.
    INPUT_TYPE current_factor = base % modulo;

    int result = 1;

    // Para cada bit possivel dentre o tipo de entrada, executar a sequencia a seguir
    for (int i = 0; i < (int) (sizeof(INPUT_TYPE) * BYTE_SIZE); i++) {

        // Se o bit de mesmo indice no expoente for positivo, multiplicar o fator atual pelo resultado
        // o que corresponde ao produtorio dos termos apresentado nas notas de aula
        if (exponent & (1 << i)) {
            printf("bit %d do expoente e 1, e seu fator apos aplicacao do modulo e %d\n", i, current_factor);

            INPUT_TYPE temp = result;
            result = (result * current_factor) % modulo;

            printf("Multiplicando o produto anterior pelo fator atual, tem-se o produto atual dos fatores:\n");
            printf("(%d * %d) (mod %d) = %d\n\n", temp, current_factor, modulo, result);
        }

        // Definir o fator atual como o quadrado do fator anterior, fazendo com que a sequencia de fatores seja igual
        // a base elevada a soma das potencias de 2 correspondentes ao binario do expoente.
        current_factor = (current_factor * current_factor) % modulo;
    }

    return result;
}

int main( int argc, char *argv[] ) {

    INPUT_TYPE base, exponent, modulo;

    if (argc == 4) {

        base = atoi(argv[1]);
        exponent = atoi(argv[2]);
        modulo = atoi(argv[3]);

        printf("Resultado da exponenciacao modular %d^%d (mod %d) = %d\n",
               base,
               exponent,
               modulo,
               modular_exponentiation(base, exponent, modulo)
        );
    }

    else
        printf("Parametros de entrada invalidos\n");

    return 0;
}
