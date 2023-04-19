#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *scan_line() {

	int size = 0;
	char *str = malloc(size * sizeof(char));
	char current_char;
	while (scanf("%c", &current_char) == 1 && current_char != '\n' && current_char != '\r') {
		str = realloc(str, ++size * sizeof(char));
		str[size - 1] = current_char;
	}
	if (size != 0) {
		str = realloc(str, (size + 1) * sizeof(char));
		str[size] = '\0';
		return str;
	} else {
		free(str);
		return "\0";
	}
}

unsigned char* read_wav(char *file_name, int *size) {
    FILE* fp = fopen(file_name, "rb");
    unsigned char buf4[4];

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    int dataSize = buf4[0] | buf4[1]<<8 | buf4[2]<<16 | buf4[3]<<24;

    unsigned char* data = malloc(sizeof(*data) * (dataSize));

    int i = 0;
    while (i < dataSize) {
        fread(&data[i++], sizeof(unsigned char), 1, fp);
    }
    *size = dataSize;

    fclose(fp);
    return data;
}

void write_wav(char *original_file_name, char *new_file_name, unsigned char *data, int size) {

    FILE* original_pointer = fopen(original_file_name, "rb");

    unsigned char *header = malloc(44 * sizeof(unsigned char));
    fread(header, sizeof(unsigned char), 44, original_pointer);
    fclose(original_pointer);

	FILE* new_pointer = fopen(new_file_name, "wb");

	fwrite(header, sizeof(unsigned char), 44, new_pointer);
	free(header);

	fwrite(data, sizeof(unsigned char), size, new_pointer);

    fclose(new_pointer);
}