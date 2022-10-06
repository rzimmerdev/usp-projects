#include <stdio.h>
#include <stdlib.h>

int get_longest(int *seq, int **longest, int i, int n) {
    if (i >= n)
        return 0;
    if ((*longest)[i] != -1)
        return (*longest)[i];
    if (i == n - 1) {
        return 1;
    }
    int size = 0;

    if (seq[i] <= seq[i + 1])
        size += get_longest(seq, longest, i + 1, n);
    (*longest)[i] = size;
    return size;
}


int main() {

    int n;
    scanf("%d\n", &n);

    int *seq = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d ", &val);
        seq[i] = val;
    }

    int *longest = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        longest[i] = -1;
    }

    int size = get_longest(seq, &longest, 0, n);
    printf("%d\n", size);
    free(seq);
    free(longest);


    return 0;
}