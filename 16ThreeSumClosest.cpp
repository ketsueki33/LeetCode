#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/3sum-closest/
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        // refer 4sum for approach
        // only difference here is that we use only one outer loop
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res, diff=INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                if( abs(target - sum ) < diff ){
                    diff = abs( target - sum );
                    res = sum;
                }
                if (sum == target) {
                    return target;
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                } else if (sum < target)
                    j++;
                else
                    k--;
            }
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