#include <bits/stdc++.h>

#define N_DATA 8

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

#define printMatrix(matrix) \
    { \
        foreachi(i, matrix) { \
            foreachi(j, matrix[i]) { \
                cout << matrix[i][j] << " "; \
            } \
            cout << endl; \
        } \
    }

using data_t = vector<bool>;
using board_t = vector<data_t>;

bool isSafe(const board_t &board, const int &row, const int &column) {
    // rows
    for (int i = 0; i < N_DATA; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // column
    for (int i = 0; i < N_DATA; i++) {
        if (board[i][column]) {
            return false;
        }
    }

    // back diagonal
    int rowM = row - 1;
    int columnM = column - 1;

    do {
        if (rowM < 0 || columnM < 0) {
            break;
        }
        if (board[rowM][columnM]) {
            return false;
        }
        columnM--;
        rowM--;
    } while (true);

    rowM = row - 1;
    columnM = column + 1;

    do {
        if (rowM < 0 || columnM > N_DATA - 1) {
            break;
        }
        if (board[rowM][columnM]) {
            return false;
        }
        columnM++;
        rowM--;
    } while (true);

    rowM = row + 1;
    columnM = column - 1;

    do {
        if (rowM > N_DATA - 1 || columnM < 0) {
            break;
        }
        if (board[rowM][columnM]) {
            return false;
        }
        columnM--;
        rowM++;
    } while (true);

    // forward diagonal
    rowM = row + 1;
    columnM = column + 1;
    do {
        if (rowM > N_DATA - 1 || columnM > N_DATA - 1) {
            break;
        }
        if (board[rowM][columnM]) {
            return false;
        }
        columnM++;
        rowM++;
    } while (true);

    return true;
}

board_t copyBoard(const board_t &board) {
    board_t newBoard = board_t(8, data_t(8, false));
    for (int i = 0; i < N_DATA; i++) {
        for (int j = 0; j < N_DATA; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
    return newBoard;
}

void solveNQueen(board_t board, int currentRow, const int &preselectedRow, const int &preselectedColumn,
                 vector<board_t> &solutions) {
    if (currentRow == N_DATA) {
        solutions.push_back(copyBoard(board));
        return;
    }

    if (currentRow == preselectedRow) {
        solveNQueen(board, currentRow + 1, preselectedRow, preselectedColumn, solutions);
        return;
    }

    for (int i = 0; i < N_DATA; i++) {
        if (i == preselectedColumn) {
            continue;
        }
        if (isSafe(board, currentRow, i)) {
            board[currentRow][i] = true;
            solveNQueen(board, currentRow + 1, preselectedRow, preselectedColumn, solutions);
            board[currentRow][i] = false;
        }
    }
}


vector<int> findAllQueens(const board_t &board) {
    vector<int> solutions = vector<int>(8, 0);
    foreachi(i, board) {
        foreachi(j, board[i]) {
            if (board[i][j]) {
                solutions[j] = i;
            }
        }
    }
    return solutions;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int preselectedRow;
        int preselectedColumn;
        vector<board_t> solutions;
        board_t board = board_t(N_DATA, data_t(N_DATA, false));

        cin >> preselectedRow >> preselectedColumn;

        preselectedRow--;
        preselectedColumn--;
        board[preselectedRow][preselectedColumn] = true;
        solveNQueen(board, 0, preselectedRow, preselectedColumn, solutions);

        cout << "SOLN       COLUMN" << endl;
        cout << " #      " << "1 2 3 4 5 6 7 8" << endl << endl;

        vector<vector<int>> solTotal;
        foreach(b, solutions) {
            solTotal.push_back(findAllQueens(b));
        }
        std::sort(solTotal.begin(), solTotal.end());

        foreachi(i, solutions) {
            auto p = i + 1;
            if (to_string(p).size() == 2) {
                cout << p << "      ";
            } else {
                cout << " " << p << "      ";
            }
            foreachi(m, solTotal[i]) {
                if (m == N_DATA - 1) {
                    cout << solTotal[i][m] + 1;
                } else {

                    cout << solTotal[i][m] + 1 << " ";
                }
            }
            cout << endl;
        }
        if (n != 0) {
            cout << endl;
        }
    }
}