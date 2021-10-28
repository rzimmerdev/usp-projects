input_size gcd_extended(input_size divisor, input_size dividend,
				 		input_size *i, input_size *j, int spacing)
{
	for (int i = 0; i < spacing; i++) { printf(" "); }
	if (spacing != 0) {
		printf("└- Iteraca %d -> Dividendo: %ld; Divisor: %ld\n", spacing, dividend, divisor);
	}

	input_size i_temporary, j_temporary;

	// Caso base da funcao recursiva,
	// retorna o ultimo dividendo quando o divisor e 0 (Resto anterior foi 0)
	if (divisor == 0) {
		*i = 0;
		*j = 1;

		for (int i = 0; i < spacing; i++) { printf(" "); }
		printf(" => Maior divisor em comum: %ld\n", dividend);
		return dividend;
	}

	input_size modulo = dividend % divisor;
	input_size recursive_extended = gcd_extended(modulo, divisor, &i_temporary, &j_temporary, spacing + 1);

	// Pela equacao dividendo * i + divisor * j = 1,
	// e possível atribuir a i e j valores a medida que
	// a funcao recursiva e retornada
	*i = j_temporary - (dividend / divisor) * i_temporary;
	*j = i_temporary;

	return recursive_extended;
}
