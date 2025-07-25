#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2, int ind, int mask, vector<vector<int>> &dp) {
        if (ind == nums1.size()) return 0;
        if (dp[ind][mask] != -1) return dp[ind][mask];

        int result = INT_MAX;

        for (int j = 0; j < nums1.size(); j++) {
            if (!(mask & (1 << j))) {
                int newMask = mask | (1 << j);
                int xorSum = (nums1[ind] ^ nums2[j]) + f(nums1, nums2, ind + 1, newMask, dp);
                result = min(result, xorSum);
            }
        }

        return dp[ind][mask] = result;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        return f(nums1, nums2, 0, 0, dp);
    }
};


class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int mini = INT_MAX;
        sort(nums2.begin(), nums2.end());

        do{
            int xr = 0;
            for(int i = 0; i < nums1.size(); i++){
                xr += nums1[i] ^ nums2[i];
            }
            mini = min(mini, xr);
        } while (next_permutation(nums2.begin(), nums2.end()));

        return  mini;
    }
};




int main() {

    return 0;
}