<<<<<<< HEAD
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
=======

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int red(int a) {
    return a % (int) (1e9 + 7);
}


int get_paths(int **squares, int ***paths, int i, int j, int H, int W) {
    if ((i >= H || j >= W) || squares[i][j] == 0)
        return 0;
    if ((*paths)[i][j] != -1)
        return (*paths)[i][j];
    else {
        int total = ((i == H - 1) && (j == W - 1)) ? 1 : 0;

        total += get_paths(squares, paths, i + 1, j, H, W) + get_paths(squares, paths, i, j + 1, H, W);

        total = red(total);

        (*paths)[i][j] = total;
        return total;
    }
}


int main() {

    int H, W;
    scanf("%d %d\n", &H, &W);

    int **squares = (int **) malloc(sizeof(int *) * (H));
    int **paths = (int **) malloc(sizeof(int *) * (H));
    for (int i = 0; i < H; i++) {
        squares[i] = (int *) malloc(sizeof(int) * (W));
        paths[i] = (int *) malloc(sizeof(long int) * (W));
        memset(paths[i], -1, sizeof(long int) * (W));

        for (int j = 0; j < W; j++) {
            char d;
            scanf("%c", &d);
            squares[i][j] = (d == '.') ? 1 : 0;
        }
        getchar();
    }

    int total = get_paths(squares, &paths, 0, 0, H, W);
    printf("%d\n", total);

    for (int i = 0; i < H; i++) {
        free(squares[i]);
        free(paths[i]);
    }
    free(squares); free(paths);

    return 0;
>>>>>>> 4f246df97eb3353b3707331524cdc05b6e626d44
}