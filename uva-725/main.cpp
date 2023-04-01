#include <bits/stdc++.h>

using namespace std;

// fghij is between 01234 and 98765
// N is the input

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int counter = 0;

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        if (counter != 0) {
            cout << endl;
        }
        counter++;
        bool existsSol = false;
        for (int i = 1234; i < 98766; i++) {
            int first = i * n;
            if (first > 98766) continue;
            string firstStr = to_string(first);
            firstStr.insert(0, 5 - firstStr.length(), '0');

            string iStr = to_string(i);
            iStr.insert(0, 5 - iStr.length(), '0');

            vector<char> firstVec(firstStr.begin(), firstStr.end());
            vector<char> secondVec(iStr.begin(), iStr.end());

            firstVec.insert(firstVec.end(), secondVec.begin(), secondVec.end());

            auto firstSet = set<char>(firstVec.begin(), firstVec.end());
            if (firstSet.size() == 10) {
                existsSol = true;
                cout << firstStr << " / " << iStr << " = " << n << endl;
            }
        }
        if (!existsSol) {
            cout << "There are no solutions for 61." << endl;
        }
    }
    return 0;
}
