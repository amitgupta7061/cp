#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int l = 0, r = 0, maxSum = INT_MIN, currSum = 0;

        while (r < nums.size()) {
            while (seen.count(nums[r])) {
                seen.erase(nums[l]);
                currSum -= nums[l];
                l++;
            }

            seen.insert(nums[r]);
            currSum += nums[r];

            maxSum = max({maxSum, currSum, nums[r]});

            r++;
        }

        return maxSum;
    }
};



int main() {

    return 0;
}