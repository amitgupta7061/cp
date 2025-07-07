#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n <= 3) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

int main() {

    return 0;
}