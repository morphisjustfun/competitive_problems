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

bool satisfy(double x, double y, double z, int A, int B, int C) {
    bool conditionA = (x + y + z) == A;
    bool conditionB = (x * y * z) == B;
    bool conditionC = (x * x + y * y + z * z) == C;
    bool conditionD = x != y && x != z && y != z;

    return conditionA && conditionB && conditionC && conditionD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string initialLine;
    getline(cin, initialLine);
    int n = atoi(initialLine.c_str());

    while (n--) {
        string line;
        getline(cin, line);
        vector<string> numbersStr;
        tokenize(line, ' ', numbersStr);
        vector<int> numbers;
        foreach(str, numbersStr) {
            numbers.push_back(atoi(str.c_str()));
        }
        int A = numbers[0];
        int B = numbers[1];
        int C = numbers[2];

        // 1/x + 1/y + 1/z
        double inverseSum = (pow(A, 2) - C) / (2 * B);

        vector<vector<int>> allSolutions;
        for (int x = 1; x <= B; x++) {
            if ((B % x) != 0) {
                continue;
            }
            for (int y = 1; y <= B / x; y++) {
                if ((B % (x * y)) != 0) {
                    continue;
                }
                for (int z = 1; z <= B / (x * y); z++) {
                    if ((x * y * z) != B){
                        continue;
                    }
                    int negx = -1 * x;
                    int negy = -1 * y;
                    int negz = -1 * z;

                    // neg x and y
                    if (satisfy(negx, negy, z, A, B, C)) {
                        allSolutions.push_back({negx, negy, z});
                    }

                    // neg x and z
                    if (satisfy(negx, y, negz, A, B, C)) {
                        allSolutions.push_back({negx, y, negz});
                    }

                    // neg y and z
                    if (satisfy(x, negy, negz, A, B, C)) {
                        allSolutions.push_back({x, negy, negz});
                    }

                    // all positives
                    if (satisfy(x, y, z, A, B, C)) {
                        allSolutions.push_back({x, y, z});
                    }
                }
            }
        }

        if (!allSolutions.empty()) {
            std::sort(allSolutions.begin(), allSolutions.end());
            cout << allSolutions[0][0] << " " << allSolutions[0][1] << " " << allSolutions[0][2] << endl;
        }
        else {
            cout << "No solution." << endl;
        }
    }
    return 0;
}