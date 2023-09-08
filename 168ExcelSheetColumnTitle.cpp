#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
   public:
    string convertToTitle(int columnNumber) {
        string str = "";

        while (columnNumber > 0) {
            if (columnNumber % 26 == 0) {
                str += 'Z';
                columnNumber--;
            } else {
                str += 'A' + columnNumber % 26 - 1;
            }
            columnNumber /= 26;
        }

        reverse(str.begin(), str.end());
        return str;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}