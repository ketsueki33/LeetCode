#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/sorting-three-groups/description/

class Solution
{
public:
    // Function to calculate the length of the Longest Increasing Subsequence (LIS)
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int res = 1; // Initialize the result as 1 (at least one element is in the LIS)
        vector<int> lis(n, 1); // Create a vector to store LIS lengths, initialized to 1 for each element

        // Iterate through the input array in reverse order
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Check if the current element can be included in the LIS
                if (nums[i] <= nums[j])
                {
                    // Update the LIS length for the current element
                    lis[i] = max(lis[i], lis[j] + 1);
                    // Update the overall result with the maximum LIS length found
                    res = max(res, lis[i]);
                }
            }
        }
        // Return the length of the Longest Increasing Subsequence
        return res;
    }

    // Function to calculate the minimum number of operations to make the input array strictly increasing
    int minimumOperations(vector<int> &nums)
    {
        int lis = lengthOfLIS(nums); // Calculate the length of the LIS
        // The minimum number of operations is equal to the difference between the array size and the LIS length
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