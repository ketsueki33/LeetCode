#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/palindrome-number/

class Solution {
   public:
    bool isPalindrome(int x) {
        // negative numbers and non zero numbers ending with 0 can't be a palindrome
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        // the idea is to reverse the second half of the number
        // if the first half is equal to the reversed second half, it is a palindrome
        int reverse = 0;

        // the point where reverse > x is the halfway point
        while (x > reverse) {
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }

        // reverse will have an extra digit at the end if x was odd
        return (x == reverse || x == reverse / 10);
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}