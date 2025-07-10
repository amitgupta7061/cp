#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &pages, vector<int> &cost, int ind, int rs, vector<vector<int>>& dp){
    if(ind >= pages.size() or rs <= 0) return 0;
    if(dp[ind][rs] != -1) return dp[ind][rs];
    int c = 0;
    if(cost[ind] <= rs){
        c = pages[ind] + f(pages, cost, ind+1, rs-cost[ind], dp);
    }
    return dp[ind][rs] = max(c, f(pages, cost, ind+1, rs, dp));
}

int main() {

    int n, x;
    cin>>n>>x;

    vector<int> pages(n), cost(n);
    for(int i = 0; i < n; i++) cin>>cost[i];
    for(int i = 0; i < n; i++) cin>>pages[i];

    vector<vector<int>> dp(n, vector<int>(x+1, -1));

    cout<<f(pages, cost, 0, x, dp);
    return 0;
}