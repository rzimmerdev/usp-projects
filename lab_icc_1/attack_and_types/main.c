// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Adding Padding to Centered Image
// 23/07/2021

#include <stdio.h>
#include <stdlib.h>

int main() {

	int total_types;
	scanf("%d", &total_types);

	double types_relation[total_types][total_types];

	for (int i = 0; i < total_types; i++) {
		for (int j = 0; j < total_types; j++) {
			scanf("%lf ", &types_relation[i][j]);
		}
	}

	int (*attacks)[2] = calloc(0, 2 * sizeof(int));

	int current_damage, current_type, total_attacks = 0;
	while ((scanf("%d ", &current_damage)) != EOF && current_damage != -1) {

		scanf("%d ", &current_type);

		attacks = realloc(attacks, 2 * sizeof (int) * (++total_attacks));

		attacks[total_attacks - 1][0] = current_damage;
		attacks[total_attacks - 1][1] = current_type;

	}

	int enemy_type;
	scanf("%d", &enemy_type);

	double best_damage = 0;
	int best_attack_id = 0;

	for (int i = 0; i < total_attacks; i++) {
		if (best_damage < attacks[i][0] * types_relation[attacks[i][1]][enemy_type]) {

			best_damage = attacks[i][0] * types_relation[attacks[i][1]][enemy_type];
			best_attack_id = i;

		}
	}

	free(attacks);
	printf("O melhor ataque possui indice %d e dano %.2lf", best_attack_id, best_damage);

	return 0;

}