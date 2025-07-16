#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];

        int cnt = 0;
        for (int num : nums) {
            if (target - num >= 0) {
                cnt += f(nums, target - num, dp);
            }
        }
        return dp[target] = cnt;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return f(nums, target, dp);
    }
};


int main() {

    return 0;
}