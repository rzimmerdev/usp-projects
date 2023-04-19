#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 * Reads a single matrix of preferences, saving either the desired order of partners or the dependency of preferences
 * based on the other partner, based on the sex currently being read.
 */
void read_preferences(vector<vector<int>>* pref_list, int pairs_size, int is_male) {

    int self_index, other_index;

    // Iterate over each person's preference, and keep track of all lines left
    for (int line = 0; line < pairs_size; line++) {

        // Read the current person's index, as to preserve the order when inserting into the preference matrix
        cin >> self_index;
        self_index -= 1;

        // Read each preference column
        for (int preference = 0; preference < pairs_size; preference++) {
            cin >> other_index;
            other_index -= 1;

            // If the preferences read are for males, store preferences in descending order,
            // else (if preferences are for women), store them based on the dependent partner.
            if (is_male)
                (*pref_list)[self_index][preference] = other_index;
            else
                (*pref_list)[self_index][other_index] = preference;
        }
    }
}


void engage(pair<vector<int>, vector<int>> *table, int priority, int male, int fem) {
    /*
     * Stores to the engagement table the relationship between the engaged female, the priority of the relationship
     * according to the female and the male to whom she is married, in case a new male with higher priority comes along.
     */
    (*table).first[fem] = priority;
    (*table).second[fem] = male;
}


void stable_marriage(pair<vector<int>, vector<int>> *engagements, vector<vector<int>> male_pref, vector<vector<int>> fem_pref, int pairs_size) {
    /*
     * Algorithm for finding a stable marriage setup between all candidates, given their preference matrices, as well
     * as a table storing all relationships engagements, such as the current priority and the engaged male.
     * This algorithm prioritizes the preference of the males, using the engagement table and the female preference
     * matrix only if two males are competing over one female.
     */

    // Keep track of all males that are still single, using a queue (FIFO)
    queue<int> single;
    for (int male = 0; male < pairs_size; male++)
        single.push(male);

    // While there is still a single male, find a new suitable partner
    while (!single.empty()) {
        int male = single.front();
        single.pop();

        // Iterate over the males preference list in descending order
        for (int preference = 0; preference < pairs_size; preference++) {
            int fem = male_pref[male][preference];

            // If there is any female that is still single, propose
            if ((*engagements).first[fem] == -1) {
                engage(engagements, fem_pref[fem][male], male, fem);
                break;
            }

            // Otherwise, see if the competing male doesn't attract the female as much as the current male
            else if ((*engagements).first[fem] > fem_pref[fem][male]) {
                single.push((*engagements).second[fem]);
                engage(engagements, fem_pref[fem][male], male, fem);
                break;
            }
        }
    }
}


vector<int> switch_order(vector<int> &females, int pairs_size) {
    /*
     * Since the algorithm stores the preference disadvantage based on the females being competed over,
     * and the final output is according to the ascending ids of males, switch the order of the engagement table
     * for printing the output.
     */
    vector<int> males(pairs_size);

    for (int i = 0; i < pairs_size; i++) {
        males[females[i]] = i;
    }

    return males;
}


int main() {

    int total_cases;
    cin >> total_cases;

    // Read the list of pairs (males and females), their preferences and call the algorithm to form a
    // stable marriage setup between every member
    for (int i = 0; i < total_cases; i++) {

        int pairs_size;
        cin >> pairs_size;

        vector<vector<int>> male_pref(pairs_size, vector<int> (pairs_size, 0));
        vector<vector<int>> fem_pref(pairs_size, vector<int> (pairs_size, 0));

        // Reads from the console the preferences of both the females and the males, respectively
        read_preferences(&fem_pref, pairs_size, false);
        read_preferences(&male_pref, pairs_size, true);

        // First: vector<int>, where index = preference of the current engagement for a female (index)
        // Second: vector<int>, where index = current engagement male for a female (index)
        pair<vector<int>, vector<int>> engagements(vector<int>(pairs_size, -1), vector<int>(pairs_size, -1));
        stable_marriage(&engagements, male_pref, fem_pref, pairs_size);

        for (auto male: switch_order(engagements.second, pairs_size)) {
            cout << engagements.second[male] + 1 << " " << male + 1 << endl;
        }
    }

    return 0;
}