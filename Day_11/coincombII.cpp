#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &coins, int ind, int k, vector<vector<int>> &dp){
    if(k == 0) return 1;
    if(ind >= coins.size()) return 0;
    if(dp[ind][k] != -1) return dp[ind][k];
    int take = 0;
    if(coins[ind] <= k){
        take = f(coins, ind, k-coins[ind], dp);
    }

    return dp[ind][k] = take + f(coins, ind + 1, k, dp);
}

int main() {

    int n, x;
    cin>>n>>x;

    vector<int> coins(n);
    for(auto &it : coins) cin>>it;

    //vector<vector<int>> dp(n, vector<int>(x+1, -1));

    // cout<<f(coins, 0, x, dp); tle

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[x] << endl;


    return 0;
}