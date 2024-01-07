#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        string dobl = s + s;
        dobl.erase(0, 1);
        dobl.erase(dobl.length() - 1, 1);
        return ((dobl).find(s) != string::npos);
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    Solution obj;
    cout << obj.repeatedSubstringPattern("ababab");

    return 0;
}