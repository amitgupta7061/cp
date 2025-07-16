#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &prices, int ind, bool buy, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(prices, ind+1, false, dp), f(prices, ind+1, true, dp));
        } else{
            profit = max(prices[ind] + f(prices, ind+2, true, dp), f(prices, ind+1, false, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, 0, true, dp);
    }
};

int main() {

    return 0;
}