#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare_start(const pair<double, double> &a, const pair<double, double> &b) {
    return (a.first < b.first);
}

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
    int count = 0;

    int current_sprinkler = 0, next_sprinkler = 1, best_sprinkler = 1;
    double best_distance = -1;

    if (num_sprinklers <= 0 || sprinklers[0].first > 0 || sprinklers[num_sprinklers - 1].second < strip_length)
        return -1;

    while (current_sprinkler < num_sprinklers) {

        while (next_sprinkler < num_sprinklers && has_overlay(sprinklers[current_sprinkler], sprinklers[next_sprinkler])) {

            if (best_distance < sprinklers[next_sprinkler].second) {
                best_distance = sprinklers[next_sprinkler].second;
                best_sprinkler = next_sprinkler;
            }

            next_sprinkler++;
        }

        if (next_sprinkler >= num_sprinklers) {
            current_sprinkler = best_sprinkler;
            break;
        }
        if (current_sprinkler == best_sprinkler)
            return -1;
        current_sprinkler = best_sprinkler;
    }

    if (sprinklers[current_sprinkler].second < strip_length)
        return -1;
    return 1;
}


void print_sprinklers(vector<pair<double, double>> sprinklers, int num_sprinklers) {

    for (int i = 0; i < num_sprinklers; i++)
        cout << sprinklers[i].first << " ";
    cout << "\n";
    for (int i = 0; i < num_sprinklers; i++)
        cout << sprinklers[i].second << " ";
    cout << "\n\n";
}


int main() {

    int num_sprinklers;
    double strip_length, strip_width;
    double sprinkler_pos, sprinkler_radius;

    while (cin >> num_sprinklers) {
        cin >> strip_length >> strip_width;

        vector<pair<double, double>> sprinklers(num_sprinklers);

        int useless_sprinklers = 0;

        for (int i = 0; i < num_sprinklers; i++) {

            cin >> sprinkler_pos >> sprinkler_radius;

            if (sprinkler_radius <= strip_width / 2) {
                useless_sprinklers++;
                continue;
            }
            sprinklers[i - useless_sprinklers] = get_range(sprinkler_pos, sprinkler_radius, strip_width);
        }

        num_sprinklers -= useless_sprinklers;
        sprinklers.resize(num_sprinklers);
        sort(sprinklers.begin(), sprinklers.end(), compare_start);
        cout << count_sprinklers(sprinklers, num_sprinklers, strip_length) << "\n";
    }

    return 0;
}