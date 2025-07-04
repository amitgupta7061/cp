#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            if((n >> i) & 1) cnt++;
        }
        return cnt;
    }
};


int main() {

    return 0;
}