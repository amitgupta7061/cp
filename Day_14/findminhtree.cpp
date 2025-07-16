#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findheight(vector<int> adj[], int src, int n){
        queue<int> q;
        q.push(src);
        int height = 0;
        vector<int> visited(n, false);
        visited[src] = true;

        while(q.size()){
            for(int i = q.size(); i > 0; i--){
                int node = q.front(); q.pop();
                for(auto neigh : adj[node]){
                    if(!visited[neigh]){
                        q.push(neigh);
                        visited[neigh] = true;
                    }
                }
            }
            height++;
        }
        return height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> height(n);
        int minheight = 9999;

        for(int i = 0; i < n; i++){
            height[i] = findheight(adj, i, n);
            minheight = min(minheight, height[i]);
        }

        vector<int> result;

        for(int i = 0; i < n; i++){
            if(height[i] == minheight) result.push_back(i);

        }
        return result;
    }
};


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<int> adj[n], indegree(n, 0);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1) q.push(i);
        }

        vector<int> result;

        while(!q.empty()){
            int size = q.size();
            result.clear(); 
            for(int i = 0; i < size; i++){
                int node = q.front(); q.pop();
                result.push_back(node);

                for(int neighbor : adj[node]){
                    indegree[neighbor]--;
                    if(indegree[neighbor] == 1){
                        q.push(neighbor);
                    }
                }
            }
        }

        return result;
    }
};


int main() {

    return 0;
}