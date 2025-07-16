#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int left, int right, vector<vector<int>> &dp) {
        if (left + 1 == right) return 0;
        if (dp[left][right] != -1) return dp[left][right];

        int ans = 0;
        for (int i = left + 1; i < right; ++i) {
            int coins = nums[left] * nums[i] * nums[right];
            coins += f(nums, left, i, dp) + f(nums, i, right, dp);
            ans = max(ans, coins);
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return f(nums, 0, n + 1, dp);
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 5, 8};
    cout << s.maxCoins(nums) << endl;  // Output: 167
    return 0;
}
