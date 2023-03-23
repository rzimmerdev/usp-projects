
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
}