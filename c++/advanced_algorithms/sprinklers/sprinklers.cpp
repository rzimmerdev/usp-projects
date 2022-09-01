#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

pair<double, double> get_range(double x, double r, double w) {
    /*
     * Converts a circular range element into its respective useful range,
     * using the Pythagorean Theorem.
     */
    double half_range = sqrt(pow(r, 2) - pow(w / 2, 2));
    return make_pair(x - half_range, x + half_range);
}

bool has_overlay(pair<double, double> first_range, pair<double, double> second_range) {
    /*
     * Returns the comparison if two sprinklers overlay their useful range.
     */
    if (first_range.first < second_range.first)
        return second_range.first < first_range.second;
    else
        return first_range.first < second_range.second;
}

int count_sprinklers(vector<pair<double, double>> sprinklers, int num_sprinklers, double strip_length) {
    /*
     * Counts how many useful sprinklers are needed to totally cover a desired strip, with given length.
     */
    int count = 0;

    int current_sprinkler = 0, next_sprinkler = 1, best_sprinkler = -1;
    double best_distance = -1;

    if (num_sprinklers <= 0 || sprinklers[0].first > 0)
        return -1;

    // While there are currently any sprinklers left to iterate through, and the area is still not covered
    while (current_sprinkler < num_sprinklers) {

        // Iterate over sprinklers that overlay the currently selected sprinkler
        while (next_sprinkler < num_sprinklers && has_overlay(sprinklers[current_sprinkler],
                                                              sprinklers[next_sprinkler])) {
            if (best_distance < sprinklers[next_sprinkler].second) {
                best_distance = sprinklers[next_sprinkler].second;
                best_sprinkler = next_sprinkler;
            }
            next_sprinkler++;
        }

        // Jump to next best sprinkler decided beforehand, increase count and continue
        // If the next best sprinkler also fills the area correctly, end counting
        count++;
        if (current_sprinkler == best_sprinkler)
            return -1;

        current_sprinkler = best_sprinkler;
        if (next_sprinkler >= num_sprinklers || sprinklers[current_sprinkler].second >= strip_length)
            break;
    }

    return (sprinklers[current_sprinkler].second < strip_length) ? -1: count;
}


int main() {

    int num_sprinklers;
    double strip_length, strip_width;
    double sprinkler_pos, sprinkler_radius;

    // Go over all test cases, until no other input can be read
    while (cin >> num_sprinklers) {
        cin >> strip_length >> strip_width;

        vector<pair<double, double>> sprinklers;

        int useless_sprinklers = 0;

        // Read each individual sprinkler from input line
        for (int i = 0; i < num_sprinklers; i++) {

            cin >> sprinkler_pos >> sprinkler_radius;

            if (sprinkler_radius <= strip_width / 2) {
                useless_sprinklers++;
                continue;
            }
            sprinklers.push_back(get_range(sprinkler_pos, sprinkler_radius, strip_width));
        }

        // Add an empty sprinkler to ignore sprinklers that are not within the acceptable range
        sprinklers.emplace_back((double) -1e18, 0);

        num_sprinklers = (int) sprinklers.size();

        sort(sprinklers.begin(), sprinklers.end());
        cout << count_sprinklers(sprinklers, num_sprinklers, strip_length) << "\n";
    }

    return 0;
}