#include <bits/stdc++.h>
using namespace std;
#define pairr pair<long long, int>

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pairr>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    dist[1][0] = 0;

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    pq.push({0, 1, 0}); // {cost, node, used}

    while (pq.size()) {
        auto [cost, node, used] = pq.top(); pq.pop();

        if (cost > dist[node][used]) continue;

        for (auto [neigh, neigh_cost] : adj[node]) {
            if (dist[neigh][used] > dist[node][used] + neigh_cost) {
                dist[neigh][used] = dist[node][used] + neigh_cost;
                pq.push({dist[neigh][used], neigh, used});
            }

            if (used == 0) {
                long long discounted = dist[node][0] + neigh_cost / 2;
                if (dist[neigh][1] > discounted) {
                    dist[neigh][1] = discounted;
                    pq.push({dist[neigh][1], neigh, 1});
                }
            }
        }
    }

    cout << dist[n][1] << '\n';
    return 0;
}