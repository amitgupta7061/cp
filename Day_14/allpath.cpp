#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<vector<int>> &graph, int src, vector<int> &visited, vector<int> &temp, 
        vector<vector<int>> &result){
        temp.push_back(src);
        visited[src] = 1;

        if(src == graph.size() - 1){
            result.push_back(temp); 
        }

        for(auto &neigh : graph[src]){
            if(!visited[neigh]){
                f(graph, neigh, visited, temp, result);
            }
        }

        temp.pop_back();
        visited[src] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp, visited(graph.size(), 0);
        f(graph, 0, visited, temp, result);
        return result;
    }
};

int main() {

    return 0;
}