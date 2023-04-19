#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int red(int a) {
    return a % (int) (1e9 + 7);
}


int main() {

    int H, W;
    scanf("%d %d\n", &H, &W);

    int **paths = (int **) malloc(sizeof(int *) * (H + 1));
    for (int i = 0; i <= H; i++) {
        paths[i] = (int *) malloc(sizeof(int) * (W + 1));
        memset(paths[i], 0, sizeof(int) * (W + 1));
    }

    paths[0][1] = 1;

    for (int i = 0; i < H; i++) {

        char line[W];
        scanf("%s\n", line);
        for (int j = 0; j < W; j++) {
            if (line[j] == '.')
                paths[i + 1][j + 1] = red(paths[i][j + 1] + paths[i + 1][j]);
        }
    }
    int total = paths[H][W];
    printf("%d\n", total);

    for (int i = 0; i <= H; i++) free(paths[i]);
    free(paths);

    return 0;
}