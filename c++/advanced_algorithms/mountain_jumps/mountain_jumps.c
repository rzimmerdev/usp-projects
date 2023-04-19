#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int x, int y) {
    return (x < y) ? x : y;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int cost(int *energy, int *heights, int size, int curr) {

    if (energy[curr] != -1)
        return energy[curr];
    else {
        int x = 0, y = 0;

        if (curr + 1 < size)
            x = abs(heights[curr] - heights[curr + 1]) + cost(energy, heights, size, curr + 1);
        if (curr + 2 < size)
            y = abs(heights[curr] - heights[curr + 2]) + cost(energy, heights, size, curr + 2);


        int curr_cost = (curr + 1 < size && curr + 2 < size) ? min(x, y) : max(x, y);
        energy[curr] = curr_cost;

        return curr_cost;
    }
}


int main() {

    int n;
    scanf("%d\n", &n);

    int *energy = malloc(sizeof(int) * n);
    int *heights = malloc(sizeof(int) * n);
    memset(energy, -1, sizeof(int) * n);

    int h, i;

    for (i = 0; i < n; i++) {
        scanf("%d ", &h);
        heights[i] = h;
    }

    int least = cost(energy, heights, n, 0);
    printf("%d\n", least);

    free(energy); free(heights);

    return 0;
}