#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size;
    
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find_parent(int node){
        if(parent[node] == node) return node;
        else return parent[node] = find_parent(parent[node]);
    }

    void union_by_size(int u, int v){
        int parent_u = find_parent(u), parent_v = find_parent(v);
        if(parent_u == parent_v) return;
        if(size[parent_u] < size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }

        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet d(n+1);
        vector<int> result;

        for(auto it : edges){
            int u = it[0], v = it[1];

            if(d.find_parent(u) == d.find_parent(v)){
                result.push_back(u);
                result.push_back(v);
            }
            else {
                d.union_by_size(u, v);
            }
        }

        return result;
    }
};

int main() {

    return 0;
}