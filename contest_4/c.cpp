#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &it : nums) cin >> it;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        if (i - nums[i] >= 0) adj[i - nums[i]].push_back(i);
        if (i + nums[i] < n) adj[i + nums[i]].push_back(i);
    }

    vector<int> dist(n, -1);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if ((i - nums[i] >= 0 and (nums[i - nums[i]] % 2 != nums[i] % 2)) or
            (i + nums[i] < n and (nums[i + nums[i]] % 2 != nums[i] % 2))) {
            dist[i] = 1;
            q.push(i);
        }
    }

    while (q.size()) {
        int curr_node = q.front(); q.pop();

        for (int neigh : adj[curr_node]) {
            if (dist[neigh] == -1) {
                dist[neigh] = dist[curr_node] + 1;
                q.push(neigh);
            }
        }
    }

    for (int it : dist) cout << it << " ";
    cout << endl;

    return 0;
}
