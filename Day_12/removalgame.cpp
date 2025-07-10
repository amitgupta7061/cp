#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &scores, int l, int r, bool aChance, vector<vector<vector<int>>> &dp){
    if(l > r) return 0;
    if(dp[l][r][aChance] != -1) return dp[l][r][aChance];

    if(aChance){
        int pickLeft = scores[l] + f(scores, l+1, r, false, dp);
        int pickRight = scores[r] + f(scores, l, r-1, false, dp);
        return dp[l][r][aChance] = max(pickLeft, pickRight);
    } else {
        int pickLeft = f(scores, l+1, r, true, dp);
        int pickRight = f(scores, l, r-1, true, dp);
        return dp[l][r][aChance] = min(pickLeft, pickRight);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    for(auto &it : scores) cin >> it;

    // Add 3rd dimension to track who's turn it is
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    cout << f(scores, 0, n-1, true, dp);
    return 0;
}
