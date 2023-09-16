#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/sorting-three-groups/description/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int res = 1;
        vector<int> lis(n, 1);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] <= nums[j])
                {
                    lis[i] = max(lis[i], lis[j] + 1);
                    res = max(res, lis[i]);
                }
            }
        }
        return res;
    }

    int minimumOperations(vector<int> &nums)
    {
        int lis = lengthOfLIS(nums);
        return nums.size() - lis;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    cout << "HHELLLO";

    return 0;
}