#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

class Solution {
   public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // max heap
        priority_queue<int> pq(nums.begin(), nums.end());

        vector<vector<int>> res;

        int count = 0, prev = INT_MIN;
        while (!pq.empty()) {
            int ele = pq.top();
            pq.pop();

            if (ele == prev)
                count++;
            else
                count = 0;

            if (count == res.size())
                res.push_back({});

            res[count].push_back(ele);
            prev = ele;
        }
        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}