#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < 32; i++){
            int bitcnt = 0;
            for(auto it : nums){
                if((it >> i) & 1) bitcnt++;
            }
            if(bitcnt % 3) {
                result |= (i << 1);
            }
        }
        return result;
    }
};

int main() {

    return 0;
}