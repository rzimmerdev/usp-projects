/******************************************************************************

    Trabalho 8
    Autor: Rafael Zimmer, nUsp: 12542612

    Trabalho feito para a Disciplina Matemática Discreta.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 8
#define INPUT_TYPE unsigned short


// Usou-se a funcao do gcd_extended do trabalho 5, ja construida
INPUT_TYPE gcd_extended(INPUT_TYPE divisor, INPUT_TYPE dividend,
                        INPUT_TYPE *i, INPUT_TYPE *j)
{

    INPUT_TYPE i_temporary, j_temporary;

    // Caso base da funcao recursiva,
    // retorna o ultimo dividendo quando o divisor e 0 (Resto anterior foi 0)
    if (divisor == 0) {
        *i = 0;
        *j = 1;

        return dividend;
    }

    INPUT_TYPE modulo = dividend % divisor;
    INPUT_TYPE recursive_extended = gcd_extended(modulo, divisor, &i_temporary, &j_temporary);

    // Pela equacao dividendo * i + divisor * j = 1,
    // e possível atribuir a i e j valores a medida que
    // a funcao recursiva e retornada
    *i = j_temporary - (dividend / divisor) * i_temporary;
    *j = i_temporary;

    return recursive_extended;
}


INPUT_TYPE modular_exponentiation(INPUT_TYPE base, INPUT_TYPE exponent, INPUT_TYPE modulo) {

    unsigned int current_factor = base % modulo;

    INPUT_TYPE result = 1;

    for (int i = 0; i < (int) (sizeof(INPUT_TYPE) * BYTE_SIZE); i++) {

        if (exponent & (1 << i))
            // bit i do expoente é 1, e seu fator apos aplicação do módulo é current_factor
            result = (result * current_factor) % modulo;

        // Multiplicando o produto anterior pelo fator atual, tem-se o produto atual dos fatores:
        current_factor = (current_factor * current_factor) % modulo;
    }

    return result;
}


// p = 167, q = 311
// => n = p * q = 51937 (cabe em 16 bits < 65536)
// => phi = (167 - 1)(311-1) = 51460
// e = 24329
INPUT_TYPE set_keys(INPUT_TYPE *public, INPUT_TYPE *private) {

    INPUT_TYPE p = 167, q = 311;
    INPUT_TYPE inverse, i;

    INPUT_TYPE phi = (p - 1) * (q - 1);
    INPUT_TYPE e = 24329 % phi;

    // Para escolher um novo e:
    // e = rand() % phi;
    // while (e == 1)
    //      e = rand() % phi;

    gcd_extended(phi, e, &i, &inverse);

    *public = e;
    *private = inverse;

    return p * q;
}


int main( int argc, char *argv[] ) {

    if (argc == 3) {

        INPUT_TYPE public_key, private_key;

        INPUT_TYPE n = set_keys(&public_key, &private_key);

        if (argv[1][0] == 'c') {
            INPUT_TYPE message = (INPUT_TYPE) atoi(argv[2]);

            printf("Chave publica: %d\n", public_key);

            INPUT_TYPE encoded_message = modular_exponentiation(message, public_key, n);
            printf("Resultado da codificacao =  %hu\n", encoded_message);

        }

        else if (argv[1][0] == 'd') {
            INPUT_TYPE message = (INPUT_TYPE) atoi(argv[2]);

            printf("Chave privada: %d\n", private_key);

            INPUT_TYPE decoded_message = modular_exponentiation(message, private_key, n);
            printf("Resultado da decodificacao =  %hu\n", decoded_message);
        }
    }

    else
        printf("Parametros de entrada invalidos\n");

    return 0;
}
