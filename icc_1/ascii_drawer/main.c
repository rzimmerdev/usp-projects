// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Reverse Polonese Notation
// 21/07/2021

#include <stdio.h>
#include <stdlib.h>

char *read_console();
char *read_file(FILE *file_pointer, int *width);
void fill_area(char ***canvas, int height, int width, int x, int y, char fill_color, char placeholder_color);
void print_canvas(char **canvas, int height);

void enquadra_arte(
        char *nome_do_arquivo_da_arte,
        int  altura_do_quadro,
        int  largura_do_quadro
);

int main() {

    char *art_name = read_console();
    int total_steps;
    scanf("%d ", &total_steps);

    FILE *art_file = fopen(art_name, "r");

    int width = 1, height = 0;
    char **canvas = malloc(height * sizeof(char *));

    char *current_line;
    while ((current_line = read_file(art_file, &width))) {

        canvas = realloc(canvas, ++height * sizeof(char *));
        canvas[height - 1] = current_line;

    } fclose(art_file);

    printf("Arte inicial:\n");
    print_canvas(canvas, height);


    for (int i = 0; i < total_steps; i++) {

        char fill_color;
        int x, y;
        scanf("%c %d %d\n", &fill_color, &y, &x);

        fill_area(&canvas, height, width, x, y, fill_color, canvas[y][x]);

        printf("Arte apos a etapa %d:\n", i);
        print_canvas(canvas, height);

    }

    art_file = fopen(art_name, "w");

    for (int i = 0; i < height; i++) {

        fprintf(art_file, "%s", canvas[i]);
        if (i < height - 1) fprintf(art_file, "\n");

    }

    fclose(art_file);

    printf("Arte enquadrada:\n");
    enquadra_arte(art_name, height, width);

    return 0;
}

char *read_console() {

    // Declare line array, with dynamic size
    char *line = NULL;
    char current_char = -1;

    int index = 0, string_size = 0;

    // Keep reading until current character is NULL character (set by program)
    while (current_char) {

        // Scan character and see if is EOF or \n, then stop reading line and add null character to end of string

        if (!scanf("%c", &current_char) || current_char == '\n' || current_char == '\r') {
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

char *read_file(FILE *file_pointer, int *width) {

    int current_char, line_size = 0;
    char *line = NULL;

    while ((current_char = fgetc(file_pointer)) != EOF && current_char != '\n' && current_char != '\r') {

        line = realloc(line, sizeof(char) * ++line_size);
        line[line_size - 1] = (char) current_char;

    }; fgetc(file_pointer);

    if (line_size) *width = line_size;

    return line;

}

void fill_area(char ***canvas, int height, int width, int x, int y, char fill_color, char placeholder_color) {

    (*canvas)[y][x] = fill_color;

    if (x > 0 && (*canvas)[y][x - 1] == placeholder_color) {
        fill_area(canvas, height, width, x - 1, y, fill_color, placeholder_color);
    }

    if (x < width - 1 && (*canvas)[y][x + 1] == placeholder_color) {
        fill_area(canvas, height, width, x + 1, y, fill_color, placeholder_color);
    }

    if (y > 0 && (*canvas)[y - 1][x] == placeholder_color) {
        fill_area(canvas, height, width, x, y - 1, fill_color, placeholder_color);
    }

    if (y < height - 1 && (*canvas)[y + 1][x] == placeholder_color) {
        fill_area(canvas, height, width, x, y + 1, fill_color, placeholder_color);
    }
}

void print_canvas(char **canvas, int height) {

    for (int i = 0; i < height; i++) printf("%s\n", canvas[i]);

}

void enquadra_arte(
        char *nome_do_arquivo_da_arte,
        int  altura_do_quadro,
        int  largura_do_quadro
) {
    FILE *f_arte_ptr = fopen(nome_do_arquivo_da_arte, "r");
    if (f_arte_ptr == NULL) {
        printf(
                "Erro na abertura do arquivo, "
                "Você esqueceu de fechar o arquivo antes? "
                "Ou deu free na string com o nome sem querer?\n"
        );

        exit(EXIT_FAILURE);
    }

    int qtd_espc_comeco;
    const char *apoio;
    if (largura_do_quadro % 2 == 0) {
        qtd_espc_comeco = largura_do_quadro / 2;
        apoio           = "/\\";
    } else {
        qtd_espc_comeco = largura_do_quadro / 2 + 1;
        apoio           = "Ʌ";
    }

    for (int i = 0; i < qtd_espc_comeco; i++) printf(" ");
    printf("%s\n", apoio);

    printf("╭");
    for (int i = 0; i < largura_do_quadro; i++) printf("—");
    printf("╮\n");

    for (int i = 0; i < altura_do_quadro; i++) {
        printf("|");
        for (int j = 0; j < largura_do_quadro; j++) {
            char pixel_atual = fgetc(f_arte_ptr);
            printf("%c", pixel_atual);
        }
        printf("|");

        char quebra = fgetc(f_arte_ptr);
        if (quebra != EOF) printf("%c", quebra);
    };
    fclose(f_arte_ptr);

    printf("\n╰");
    for (int i = 0; i < largura_do_quadro; i++) printf("—");
    printf("╯\n");
}