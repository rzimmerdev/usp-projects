#include <bits/stdc++.h>

using namespace std;


int expand(vector<int> sequence, vector<int> &lengths, int pos, int size) {
    if (pos >= size)
        return 0;
    if (lengths[pos] != -1)
        return lengths[pos];

    int fixed = sequence[pos];
    int total_length = 1;

    for (int i = pos + 1; i < size; i++) {
        if (fixed < sequence[i])
            total_length = max(total_length, 1 + expand(sequence, lengths, i, size));
    }

    lengths[pos] = total_length;
    return total_length;
}


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> memo(n, -1);

    int max_length = 0;

    for (int i = 0; i < n; i++)
        max_length = max(max_length, expand(nums, memo, i, n));

    cout << max_length;

    return 0;
}