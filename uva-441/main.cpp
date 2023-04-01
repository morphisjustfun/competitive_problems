#include <bits/stdc++.h>

using namespace std;

#define tokenize(str, delim, vec) \
    { \
        stringstream ss(str); \
        string token; \
        while (getline(ss, token, delim)) { \
            vec.push_back(token); \
        } \
    }

#define foreach(i, vec) \
    for (auto const& i : vec)

#define foreachi(i, vec) \
    for (int i = 0; i < vec.size(); i++)

#define printvec(vec) \
    { \
        foreachi(i, vec) { \
            if (i != vec.size() - 1) { \
                cout << vec[i] << " ";     \
            } \
            else { \
                cout << vec[i]; \
            } \
        } \
        cout << endl; \
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int select = 6;
    int counter = 0;

    string line;
    while (getline(cin, line)) {
        if (line == "0") {
            break;
        }

        if (counter != 0) {
            cout << endl;
        }
        counter++;

        vector<string> S;
        tokenize(line, ' ', S);
        S.erase(S.begin());

        vector<int> Sint;
        foreach(element, S) {
            Sint.push_back(atoi(element.c_str()));
        }

        std::sort(Sint.begin(), Sint.end());

        vector<bool> selectors(S.size(), false);
        std::fill(selectors.begin(), selectors.begin() + select, true);

        vector<vector<int>> combinations;
        do {
            vector<int> combination;
            foreachi(i, Sint) {
                if (selectors[i]) {
                    combination.push_back(Sint[i]);
                }
            }
            set<int> combinationSet = set<int>(combination.begin(), combination.end());
            if (combination.size() == combinationSet.size()) {
                auto searchResultIterator = std::find_if(combinations.begin(), combinations.end(), [&combination](const vector<int>& v) {
                    bool result = true;
                    foreachi(i, v) {
                        if (v[i] != combination[i]) {
                            result = false;
                            break;
                        }
                    }
                    return result;
                });

                if (searchResultIterator == combinations.end()) {
                    combinations.push_back(combination);
                    printvec(combination);
                }
            }
        } while (prev_permutation(selectors.begin(), selectors.end()));
    }

    return 0;
}