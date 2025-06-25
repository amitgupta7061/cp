#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int> &nums, int pScore, int qSCore, int l, int r, bool chance){
        if(l > r){
            if(pScore >= qSCore) return true;
            else return false;
        }
        if(chance){
            return f(nums, pScore+nums[l], qSCore, l+1, r, !chance) or f(nums, pScore+nums[r], qSCore, l, r-1, !chance);
        } else{
            return f(nums, pScore, qSCore+nums[l], l+1, r, !chance) and f(nums, pScore, qSCore+nums[r], l, r-1, !chance); 
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return f(nums, 0, 0, 0, nums.size()-1, true);
    }
};

int main() {

    return 0;
}