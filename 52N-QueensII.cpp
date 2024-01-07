#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/n-queens-ii/description/

class Solution {
    vector<bool> horizontal;
    vector<bool> diag45;
    vector<bool> diag135;

   public:
    bool isValidOptimised(int row, int col, int n) {
        if (horizontal[row] == true)
            return false;
        if (diag45[row + col] == true)
            return false;
        if (diag135[row - col + n - 1] == true)
            return false;

        return true;
    }

    void queenSolver(int n, int &count, vector<string> &layout, int col) {
        if (col == n) {
            count++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isValidOptimised(row, col, n)) {
                layout[row][col] = 'Q';
                horizontal[row] = true;
                diag45[row + col] = true;
                diag135[row - col + n - 1] = true;

                queenSolver(n, count, layout, col + 1);

                layout[row][col] = '.';
                horizontal[row] = false;
                diag45[row + col] = false;
                diag135[row - col + n - 1] = false;
            }
        }
    }

    int totalNQueens(int n) {
        string str(n, '.');
        vector<string> layout(n, str);
        int count = 0;

        for (int i = 0; i < n; i++)
            horizontal.push_back(false);
        for (int i = 0; i < (2 * n) - 1; i++) {
            diag135.push_back(false);
            diag45.push_back(false);
        }

        queenSolver(n, count, layout, 0);

        return count;
    }
};


int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}