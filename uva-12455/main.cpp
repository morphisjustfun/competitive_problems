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
    int n;
    cin >> n;

    while (n--) {
        int lengthWeWant;
        cin >> lengthWeWant;
        int nBars;
        cin >> nBars;
        int nBarsCopy = nBars;

        vector<int> barLengths;
        while (nBarsCopy--) {
            int barLength;
            cin >> barLength;
            barLengths.push_back(barLength);
        }

        bool sol = false;


        int totalSum = accumulate(barLengths.begin(), barLengths.end(), 0);

        if (lengthWeWant == 0) {
            sol = true;
            goto exists;
        }
        if (totalSum == lengthWeWant) {
            sol = true;
            goto exists;
        }
        if (totalSum < lengthWeWant) {
            sol = false;
            goto exists;
        }

        for (int nTest = 1; nTest < nBars; nTest++) {
            vector<bool> selectors(nBars, false);
            fill(selectors.begin(), selectors.begin() + nTest, true);

            do {
                vector<int> combinationBars;
                foreachi(j, selectors) {
                    if (selectors[j]) {
                        combinationBars.push_back(barLengths[j]);
                    }
                }
                if (accumulate(combinationBars.begin(), combinationBars.end(), 0) == lengthWeWant) {
                    sol = true;
                    goto exists;
                }
            } while (prev_permutation(selectors.begin(), selectors.end()));
        }

        exists:
        if (sol) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
