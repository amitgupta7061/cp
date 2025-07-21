#include <bits/stdc++.h>
using namespace std;

void f(int curr, int par, int cnt, int m, vector<int>& cat, vector<vector<int>>& adj, int& result) {
    
    cat[curr] ? cnt++ : cnt = 0;
    if (cnt > m) return;

    bool flag = true;
    for (auto neigh : adj[curr]) {
        if (neigh != par) {
            flag = false;
            f(neigh, curr, cnt, m, cat, adj, result);
        }
    }

    if (flag) result++;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cat(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int result = 0;
    f(1, 0, 0, m, cat, adj, result);
    cout << result << endl;

    return 0;
}
