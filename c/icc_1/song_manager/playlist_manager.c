// Rafael Zimmer, n 12542612

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int length;
	char *title;
	char *author;
} song;

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

// Used when comparing if two songs are the same
int areEqual(song song1, song song2) {
	return (song1.author == song2.author && song1.title == song2.title && song1.length == song2.length) ? 1 : 0;
}

void print_playlist(char *playlist_title, int playlist_size, song *playlist, int playlist_header) {
	// Print formatted playlist
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

int main() {

	// Defining basic structure for playlist
	char *playlist_title = read_line();
	int playlist_size = 0, playlist_header = 0;

	// Allocate value for playlist variable, which can act as playlist_header pointer
	song *playlist = NULL;

	int command;
	scanf("%d", &command);

	// Read user commands while current command is not exit (5)
	while ( command != 5 ) {

		// Verify if song should and can be added to playlist
		if ( command == 1 && playlist_size < 15 ) {

			// Manage playlist size dynamically, using realloc to increment playlist size
			playlist = realloc(playlist, ++playlist_size * sizeof (song));
			song current_song = read_song();

			// Add song to playlist, to last index, as well as print successful operation to user
			playlist[playlist_size - 1] = current_song;
			printf("Musica %s de %s adicionada com sucesso.\n", current_song.title, current_song.author);

		}

		// If cannot be added, alert user, and suppose user won't send song information
		else if ( command == 1 && playlist_size == 15 ) {
			printf("Playlist cheia!\n");
		}

		else if ( command == 2 ) {
			print_playlist(playlist_title, playlist_size, playlist, playlist_header);
		}

		// Change currently playing song header
		else playlist_header += command == 3 ? 1 : -1;

		scanf("%d", &command);
	}

	// Free dynamically allocated variables (author & title were allocated dynamically with read_line()
	for (int i = 0; i < playlist_size; i++) {
		free(playlist[i].author);
		free(playlist[i].title);
	}

	free(playlist);

	return 0;
}