// Rafael Zimmer, n 12542612

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int length;
	char *title;
	char *author;
} song;

enum commands {
	ADD_SONG = 1,
	SHOW_SONGS,
	NEXT_SONG,
	PREVIOUS_SONG,
	SAVE_PLAYLIST,
	LOAD_PLAYLIST,
	END
};

char *read_line();

song read_song();
int areEqual(song song1, song song2);

void print_playlist(char *playlist_title, int playlist_size, song *playlist, int playlist_header);
void free_playlist(song *playlist, int playlist_size);

void save_playlist(char *playlist_name, int playlist_size, song *playlist, char *file_name);
void load_playlist(char **playlist_name, int *playlist_size, song **playlist, char *file_name);

void binaryToNum(char *binFilename);
bool file_exists(const char *filename);

int main() {

	// Defining basic structure for playlist
	char *playlist_title = read_line();
	int playlist_size = 0, playlist_header = 0;

	// Allocate value for playlist variable, which can act as playlist_header pointer
	song *playlist = NULL;

	int command;
	scanf("%d", &command);

	// Read user commands while current command is not exit (5)
	while ( command != END ) {

		switch ( command ) {

			case ADD_SONG: {

				if (playlist_size < 15) {

					// Manage playlist size dynamically, using realloc to increment playlist size
					playlist = realloc(playlist, ++playlist_size * sizeof(song));
					song current_song = read_song();

					// Add song to playlist, to last index, as well as print successful operation to user
					playlist[playlist_size - 1] = current_song;
					printf("Musica %s de %s adicionada com sucesso.\n", current_song.title, current_song.author);

				}

				// If cannot be added, alert user, and suppose user won't send song information
				else printf("Playlist cheia!\n");
				break;

			}

			case SHOW_SONGS: {

				print_playlist(playlist_title, playlist_size, playlist, playlist_header);
				break;

			}

			// Change currently playing song header
			case NEXT_SONG: {
			case PREVIOUS_SONG:

				playlist_header += command == NEXT_SONG ? 1 : -1;
				break;

			}

			case SAVE_PLAYLIST: {

				scanf(" ");
				char *file_name = read_line();

				if (file_exists(file_name)) {

					save_playlist(playlist_title, playlist_size, playlist, file_name);
					binaryToNum(file_name);
					free(file_name);

				} else {

					printf("Arquivo %s nao existe.\n", file_name);
					free(file_name);
					return 0;

				}

				break;

			}

			case LOAD_PLAYLIST:

				scanf(" ");
				char *file_name = read_line();
				if (file_exists(file_name)) {

					load_playlist(&playlist_title, &playlist_size, &playlist, file_name);
					binaryToNum(file_name);
					free(file_name);

				} else {

					printf("Arquivo %s nao existe.\n", file_name);
					free(file_name);
					return 0;

				}

				break;
		}
		scanf("%d", &command);
	}

	if (playlist) free_playlist(playlist, playlist_size);

	return 0;
}

char *read_line() {

	// Declare line array, with dynamic size
	char *line = NULL;
	char current_char = -1;

	int index = 0, string_size = 0;

	// Keep reading until current character is NULL character (set by program)
	while (current_char) {

		// Scan character and see if is EOF or \n, then stop reading line and add null character to end of string
		if (!scanf("%c", &current_char) || current_char == '\n') {
			current_char = 0;
		}

		// Increment size only if increment does not overflow current indexing of characters
		if (string_size++ <= index) {
			line = ( char* ) realloc(line, string_size);

		}

		*(line + index++) = current_char;

	}
	// Return pointer to dynamically allocated string
	return line;
}

// Read user input and return song struct
song read_song() {

	// Read empty new line from command argument
	free(read_line());

	// Read and assign values for song struct content
	char *title = read_line();
	char *author = read_line();
	int length;
	scanf("%d", &length);

	// Return structured song
	song current_song = { .length = length, .title = title, .author = author };
	return current_song;
}

// Use when comparing if two songs are the same
int areEqual(song song1, song song2) {
	return (song1.author == song2.author && song1.title == song2.title && song1.length == song2.length) ? 1 : 0;
}

// Print formatted playlist
void print_playlist(char *playlist_title, int playlist_size, song *playlist, int playlist_header) {

	printf("---- Playlist: %s ----\n", playlist_title);
	printf("Total de musicas: %d\n\n", playlist_size);

	for (int i = 0; i < playlist_size; i++) {

		// Print if song that is i'th song is at playlist header
		if (areEqual(playlist[playlist_header], playlist[i])) printf("=== NOW PLAYING ===\n");

		// Print song variable structure and content
		printf("(%d). '%s'\n", i + 1, playlist[i].title);
		printf("Artista: %s\n", playlist[i].author);
		printf("Duracao: %d segundos\n", playlist[i].length);
		printf("\n");
	}
}

// Free dynamically allocated variables (author & title were allocated dynamically with read_line()
void free_playlist(song *playlist, int playlist_size) {
	for (int i = 0; i < playlist_size; i++) {
		free(playlist[i].author);
		free(playlist[i].title);
	}

	free(playlist);
}

// Given file name, save in binary values for playlist elements
//
// Parameters: Playlist title, playlist size, playlist array and file_name
// Returns: None (Void)
void save_playlist(char *playlist_title, int playlist_size, song *playlist, char *file_name) {

	FILE * file_pointer = fopen(file_name, "wb");

	// Write playlist information, such as title, title string size and total_songs number
	int title_size = (int) strlen(playlist_title);
	fwrite(&title_size, sizeof(int), 1, file_pointer);
	fwrite(playlist_title, sizeof(char), title_size, file_pointer);

	fwrite(&playlist_size, sizeof(int), 1, file_pointer);

	// Iterate over songs in playlist, saving formatted information for each song
	for (int i = 0; i < playlist_size; i++) {

		song current_song = playlist[i];

		int current_title_str_size = (int) strlen(current_song.title);
		int current_author_str_size = (int) strlen(current_song.author);

		fwrite(&current_title_str_size, sizeof(int), 1, file_pointer);
		fwrite(current_song.title, sizeof(char), current_title_str_size, file_pointer);

		fwrite(&current_author_str_size, sizeof(int), 1, file_pointer);
		fwrite(current_song.author, sizeof(char), current_author_str_size, file_pointer);

		fwrite(&current_song.length, sizeof(int), 1, file_pointer);

	}

	fclose(file_pointer);

	printf("Playlist %s salva com sucesso.\n", file_name);

}

// Given file name, read file as binary, and set values for playlist elements based on input table format
//
// Parameters: Pointer to playlist title, pointer to playlist size, pointer to playlist array and file_name
// Returns: None (Void)
void load_playlist(char **playlist_title, int *playlist_size, song **playlist, char *file_name) {

	int title_size = 0;

	FILE * file_pointer = fopen(file_name, "rb");

	fread(&title_size, sizeof (int), 1, file_pointer);

	*playlist_title = calloc(sizeof(char), (title_size));
	fread(*playlist_title, sizeof (char), title_size, file_pointer);
	(*playlist_title)[title_size] = '\0';
	fread(playlist_size, sizeof(int), 1, file_pointer);

	*playlist = calloc(sizeof(song), (*playlist_size));
	printf("Playlist %s carregada com sucesso.\n", file_name);

	for (int i = 0; i < *playlist_size; i++) {

		song current_song;

		int current_title_str_size = 0;
		int current_author_str_size = 0;

		fread(&current_title_str_size, sizeof(int), 1, file_pointer);
		current_song.title = calloc(sizeof(char), current_title_str_size);
		fread(current_song.title, sizeof(char), current_title_str_size, file_pointer);

		fread(&current_author_str_size, sizeof(int), 1, file_pointer);
		current_song.author = calloc(sizeof(char), current_author_str_size);
		fread(current_song.author, sizeof(char), current_author_str_size, file_pointer);

		fread(&(current_song.length), sizeof(int), 1, file_pointer);

		(*playlist)[i] = current_song;
	}

	fclose(file_pointer);

}

// Given an input file name, verify if file in working directory already exists
//
// Parameters: File name (const char *)
// Returns: True if file exists (bool)
bool file_exists(const char *filename) {

	FILE *fp = fopen(filename, "rb");
	bool exists = false;

	if (fp != NULL) {

		exists = true;
		fclose(fp);

	}

	return exists;
}

// Soma polinomial que interpreta o valor binário como um valor numérico.
// Quanto mais próximo o valor de retorno, mais próximo seu binário está do ideal.
// Não há necessidade de entender o funcionamento dessa função.
//
// Parâmetros: Nome do arquivo (binFilename: char *)
// Retorno: Nada (void)
void binaryToNum(char *binFilename) {
	FILE *fp = fopen(binFilename, "rb");

	double binValue = 0;
	double accumulator = 0.01;
	char ch;
	while (fread(&ch, sizeof(char), 1, fp)) {
		binValue += (double) ch * accumulator;
		accumulator += 0.01;
	}

	fclose(fp);
	printf("%lf\n", binValue);
}
