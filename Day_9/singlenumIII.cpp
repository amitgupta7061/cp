#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto num : nums) xr ^= num;

        int rightbit = xr & -(unsigned int)xr;
        int x = 0, y = 0;
        for(auto num : nums){
            if(num & rightbit) x ^= num;
            else y ^= num;
        }
        return {x, y};
    }
};

int main() {

    return 0;
}
