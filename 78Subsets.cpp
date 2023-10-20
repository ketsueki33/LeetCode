#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/subsets/


class Solution {
   public:
    void findSubsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int index = 0) {
        if( index == nums.size() ){
            res.push_back(subset);
            return;
        }
        // 1. include the current index in the subset
        subset.push_back( nums[index]);
        findSubsets(nums, res, subset, index+1);

        // 2. exclude the current index from the subset
        subset.pop_back();
        findSubsets(nums, res, subset, index+1);
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subset;
        findSubsets( nums , res, subset);
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