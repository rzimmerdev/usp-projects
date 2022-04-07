/******************************************************************************

    Trabalho 7
    Autor: Rafael Zimmer, nUsp: 12542612

    Trabalho feito para a Disciplina Matemática Discreta.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 8
#define INPUT_TYPE unsigned int

int modular_exponentiation(INPUT_TYPE base, INPUT_TYPE exponent, INPUT_TYPE modulo) {

    INPUT_TYPE current_factor = base % modulo;

    int result = 1;

    for (int i = 0; i < (int) (sizeof(INPUT_TYPE) * BYTE_SIZE); i++) {

        if (exponent & (1 << i)) {
            printf("bit %d do expoente é 1, e seu fator apos aplicação do módulo é %d\n", i, current_factor);

            INPUT_TYPE temp = result;
            result = (result * current_factor) % modulo;

            printf("Multiplicando o produto anterior pelo fator atual, tem-se o produto atual dos fatores:\n");
            printf("(%d * %d) (mod %d) = %d\n\n", temp, current_factor, modulo, result);
        }

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

        printf("Resultado da exponenciação modular %d^%d (mod %d) = %d\n",

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
