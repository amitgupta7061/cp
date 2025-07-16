#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n); 
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> result(n), subtreeSize(n);

        function<void(int, int, int)> calculateDistances = [&](int node, int parent, int depth) {
            result[0] += depth;
            subtreeSize[node] = 1;
           
            for (int& neighbor : adj[node]) {
                if (neighbor != parent) {
                    calculateDistances(neighbor, node, depth + 1);
                    subtreeSize[node] += subtreeSize[neighbor]; 
                }
            }
        };

       
        function<void(int, int, int)> calculateresult = [&](int node, int parent, int totalDistance) {
            result[node] = totalDistance; 

            for (int& neighbor : adj[node]) {
                if (neighbor != parent) {
                    int revisedDistance = totalDistance - subtreeSize[neighbor] + n - subtreeSize[neighbor];
                    calculateresult(neighbor, node, revisedDistance);
                }
            }
        };

        calculateDistances(0, -1, 0);
        calculateresult(0, -1, result[0]);

        return result;
    }
};

int main() {

    return 0;
}