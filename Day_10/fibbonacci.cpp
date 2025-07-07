#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(n <= 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1) + fib(n-2);
    }
    int fib(int n) {
        vector<int> dp(n, -1);
        return f(n, dp);
    }
};

int main() {

    return 0;
}