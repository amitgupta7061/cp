#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>> &cost, int src, int mask, int n, vector<vector<int>> &dp) {
        if (mask == (1 << n) - 1) {
            return cost[src][0];
        }

        if (dp[src][mask] != -1) return dp[src][mask];

        int ans = INT_MAX;
        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newCost = cost[src][city] + f(cost, city, mask | (1 << city), n, dp);
                ans = min(ans, newCost);
            }
        }
        return dp[src][mask] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        return f(cost, 0, 1, n, dp);
    }
};

int main() {

    return 0;
}
