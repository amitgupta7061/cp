#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int l = 0, maxi = 0, n = nums.size(), currSum = 0;

        for(int r = 0; r < n; r++){
            while(seen.count(nums[r])){
                seen.erase(nums[l]);
                currSum -= nums[l]; l++;
            }
            seen.insert(nums[r]);
            currSum += nums[r];
            maxi = max(maxi, currSum);
        }

        return maxi;
    }
};

int main() {

    return 0;
}