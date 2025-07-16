#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzeroInd = -1, zeroInd = 0;
        while(nums[zeroInd] != 0) zeroInd++;
        if(zeroInd >= nums.size()) return;

        nonzeroInd = zeroInd + 1;
        while(nums[nonzeroInd] == 0) nonzeroInd++;
        if(nonzeroInd >= nums.size()) return;

        while(zeroInd < nums.size()){
            swap(nums[zeroInd], nums[nonzeroInd]);
            while(nums[zeroInd] != 0) zeroInd++;
            if(zeroInd >= nums.size()) return;

            while(nums[nonzeroInd] == 0) nonzeroInd++;
            if(nonzeroInd >= nums.size()) return;
        }
    }
};

int main() {

    return 0;
}