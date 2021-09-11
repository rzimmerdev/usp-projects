// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Pokedex Manager
// 27/07/2021

#include <stdio.h>
#include <stdlib.h>

// Struct for defining parameters of Pokemons, PokemonAttacks and PokemonAttributes variables
typedef struct {

	char name[20];
	int base_power;
	float accuracy;
	char class;

} PokemonAttack;
typedef struct {

	int hp;
	int attack;
	int defense;
	int special_attack;
	int special_defense;
	int speed;

} PokemonAttributes;
typedef struct {

	char name[50];
	char type_primary[20];
	char type_secondary[20];
	PokemonAttributes attributes;
	PokemonAttack attacks[4];

} Pokemon;

// Struct for comparing user input commands to int values
typedef enum {

	EXIT,
	NEW_POKEMON,
	NEW_ATTACK,
	PRINT_POKEMON,
	PRINT_ATTACK

} input_commands;

Pokemon scan_pokemon();
PokemonAttack scan_attack();
void print_pokemon(Pokemon pokemon);
void print_attack(PokemonAttack attack);

int main() {

	int current_command;

	Pokemon *pokemon_list = calloc(0, sizeof(Pokemon));
	int total_pokemons = 0;

	// Scan until currently read command is EXIT (int 0)
	while (scanf("%d ", &current_command) && current_command != EXIT) {

		switch (current_command) {

			// If command is to add new pokemon, scan user input and generate populated Pokemon struct,
			// as well as allocating memory for pokemon list array
			case (NEW_POKEMON): {

				Pokemon new_pokemon = scan_pokemon();

				pokemon_list = realloc(pokemon_list, ++total_pokemons * sizeof(Pokemon));
				pokemon_list[total_pokemons - 1] = new_pokemon;

			} break;

			// If command is to add new attack, scan to which pokemon and respectively which pokemon attack index
			// to add attack to, as well as scanning and populating PokemonAttack struct.
			case (NEW_ATTACK): {

				int pokemon_index, attack_index;

				scanf("%d %d ", &pokemon_index, &attack_index);

				PokemonAttack new_attack = scan_attack();

				pokemon_list[pokemon_index].attacks[attack_index] = new_attack;

			} break;

			// Command to print formatted Pokemon struct, as well as included attributes to console
			case (PRINT_POKEMON): {

				int pokemon_index;
				scanf("%d ", &pokemon_index);

				print_pokemon(pokemon_list[pokemon_index]);

			} break;

			// Command to print specific PokemonAttack struct to console, according to saved attack array on Pokemon.
			case (PRINT_ATTACK): {

				int pokemon_index, attack_index;
				scanf("%d %d", &pokemon_index, &attack_index);

				print_attack(pokemon_list[pokemon_index].attacks[attack_index]);

			} break;

		}
	}

	free(pokemon_list);

	return 0;
}

// Function for scanning iostream and returning Pokemon struct, with inserted values from stream
//
// Returns: Pokemon struct
Pokemon scan_pokemon() {

	Pokemon new_pokemon;
	scanf("%50[^\n] ", new_pokemon.name);
	scanf("%20[^\n] ", new_pokemon.type_primary);
	scanf("%20[^\n] ", new_pokemon.type_secondary);
	scanf("%d ", &(new_pokemon.attributes.hp));
	scanf("%d ", &(new_pokemon.attributes.attack));
	scanf("%d ", &(new_pokemon.attributes.defense));
	scanf("%d ", &(new_pokemon.attributes.special_attack));
	scanf("%d ", &(new_pokemon.attributes.special_defense));
	scanf("%d ", &(new_pokemon.attributes.speed));

	return new_pokemon;
};

// Function for scanning iostream and returning PokemonAttack struct, with inserted values from stream
//
// Returns: PokemonAttack struct
PokemonAttack scan_attack() {

	PokemonAttack new_attack;

	scanf("%20[^\n] ", new_attack.name);
	scanf("%d ", &(new_attack.base_power));
	scanf("%f ", &(new_attack.accuracy));
	scanf("%c ", &(new_attack.class));

	return new_attack;

}

// Function for printing to console formatted values of Pokemon struct
//
// Parameters: Pokemon variable
void print_pokemon(Pokemon pokemon) {

	printf("Nome do Pokemon: %s\n", pokemon.name);
	printf("Tipo primario: %s\n", pokemon.type_primary);
	printf("Tipo secundario: %s\n", pokemon.type_secondary);
	printf("Status:\n");
	printf("\tHP: %d\n", pokemon.attributes.hp);
	printf("\tAtaque: %d\n", pokemon.attributes.attack);
	printf("\tDefesa: %d\n", pokemon.attributes.defense);
	printf("\tAtaque Especial: %d\n", pokemon.attributes.special_attack);
	printf("\tDefesa Especial: %d\n", pokemon.attributes.special_defense);
	printf("\tVelocidade: %d\n\n", pokemon.attributes.speed);

}

// Function for printing to console formatted values of PokemonAttack struct
//
// Parameters: PokemonAttack variable
void print_attack(PokemonAttack attack) {

	printf("Nome do Ataque: %s\n", attack.name);
	printf("Poder base: %d\n", attack.base_power);
	printf("Acuracia: %f\n", attack.accuracy);
	printf("Classe: %c\n\n", attack.class);

}