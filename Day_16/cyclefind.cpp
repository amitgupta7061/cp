#include <bits/stdc++.h>
using namespace std;


int main() {

    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> adj(v + 1);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> dist(v+1, 1e9);
    dist[1] = 0;
    int startcycle = -1, parent = -1;

    for(int u = 1; u < v; u++){
        for(auto &[v, w] : adj[u]){
            if(dist[u] != 1e9 and dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int u = 1; u <= v; u++){
        for(auto &[v, w] : adj[u]){
            if(dist[u] != 1e9 and dist[u] + w < dist[v]){
                startcycle = v;
                parent = u;
                break;
            }
        }
    }

    vector<int> result;
    result.push_back(startcycle);
    for(auto it : adj[startcycle]){
        if(it.first == startcycle){
            result.push_back(parent); break;
        }
    }

    cout<<(startcycle != -1 ? "YES\n" : "NO\n");
    for(auto it : result) cout<<it<<" ";

    return 0;
}