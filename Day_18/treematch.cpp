#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

void dfs(int curr, int parent, vector<int> adj[], vector<vector<int>> &dp) {
    dp[curr][0] = 0;
    dp[curr][1] = 0;

    for (int neigh : adj[curr]) {
        if (neigh == parent) continue;
        dfs(neigh, curr, adj, dp);
        dp[curr][0] += max(dp[neigh][0], dp[neigh][1]);
    }

    for (int neigh : adj[curr]) {
        if (neigh == parent) continue;
        int match = 1 + dp[neigh][0] + (dp[curr][0] - max(dp[neigh][0], dp[neigh][1]));
        dp[curr][1] = max(dp[curr][1], match);
    }
}

int main() {

    int n; 
    cin >> n;

    vector<int> adj[N];
    vector<vector<int>> dp(n, vector<int>(2));

    for (int i = 1; i < n; i++) {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, adj, dp);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}
