#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//bool sort_end(const pair<double, double> &a, const pair<double, double> &b) {
//    return (a.second < b.second);
//}

pair<double, double> get_range(double x, double r, double w) {

    double half_range = sqrt(pow(r, 2) - pow(w / 2, 2));

    return make_pair(x - half_range, x + half_range);
}

bool has_overlay(pair<double, double> first_range, pair<double, double> second_range) {

    if (first_range.first < second_range.first) {

        return second_range.first < first_range.second;
    }

    else {
        return first_range.first < second_range.second;
    }
}

int count_sprinklers(vector<pair<double, double>> sprinklers, int num_sprinklers, double strip_length) {
    if (sprinklers[0].first > 0 || sprinklers[num_sprinklers - 1].second < strip_length)
        return -1;

    int current = 0, count = 0;
    double pos = 0;

    while (pos < strip_length || current >= num_sprinklers) {

        int last = 0;

        while (has_overlay(sprinklers[current], sprinklers[current + 1])) {
            last = current;
            current++;
        }

        if (last == 0)
            return -1;
    }

    return count;
}


int main() {



    int num_sprinklers;
    double strip_length, strip_width;
    double sprinkler_pos, sprinkler_radius;

    while (cin >> num_sprinklers) {
        cin >> num_sprinklers >> strip_length >> strip_width;

        vector<pair<double, double>> sprinklers(num_sprinklers);

        for (int i = 0; i < num_sprinklers; i++) {

            cin >> sprinkler_pos >> sprinkler_radius;

            sprinklers[i] = get_range(sprinkler_pos, sprinkler_radius, strip_width);
        }

        sort(sprinklers.begin(), sprinklers.end());

        cout << count_sprinklers(sprinklers, num_sprinklers, strip_length) << "\n";
    }

    return 0;
}