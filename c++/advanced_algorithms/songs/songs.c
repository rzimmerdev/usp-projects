#include <stdio.h>
#include <stdlib.h>


int binary_search(int n[], int low, int high, int value) {

    if (high >= low) {

        int center = (high + low) / 2;

        if (n[center] == value)
            return center;

        return n[center] > value ?
               binary_search(n, low, center - 1, value) :
               binary_search(n, center + 1, high, value);
    }
    return low;
}


int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);

    int total = 0;
    int *songs = malloc(sizeof(int) * total);
    int *accumulated = malloc(sizeof(int) * (total + 1));
    accumulated[0] = 0;

    for (int i = 0; i < n; i++) {
        int count, time;
        scanf("%d %d\n", &count, &time);

        for (; count > 0; count--) {
            total++;
            songs = realloc(songs, sizeof(int) * (total));
            accumulated = realloc(accumulated, sizeof(int) * (total + 1));
            songs[total - 1] = i;
            accumulated[total] = accumulated[total - 1] + time;
        }
    }

    total++;

    for (; m > 0; m--) {
        int query;
        scanf("%d ", &query);
        int find = binary_search(accumulated, 0, total - 1, query);
        printf("%d\n", songs[find - 1] + 1);
    }

    return 0;
}