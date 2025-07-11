#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> BFS(queue<pair<int, int>> &q, int m, int n, vector<vector<int>>& heights){

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        while(q.size()){
            auto [r, c] = q.front(); q.pop();
            visited[r][c] = true;

            for(auto it : direction){
                int nr = r + it.first, nc = c + it.second;
                if(nr >= 0 and nc >= 0 and nr < m and nc < n and !visited[nr][nc] and 
                    heights[nr][nc] <= heights[r][c]){
                    q.push({nr, nc});
                }
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        queue<pair<int, int>> pacific, atlantic;

        for(int i = 0; i < m; i++){
            pacific.push({i, 0});
            atlantic.push({i, n-1});
        }
        for(int i = 1; i < n; i++) pacific.push({0, i});
        for(int i = 0; i < n-1; i++) atlantic.push({m-1, i});

        vector<vector<bool>> reachBypacific  = BFS(pacific, m, n, heights);
        vector<vector<bool>> reachByatlantic = BFS(atlantic, m, n, heights);

        vector<vector<int>> result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(reachBypacific[i][j] and reachByatlantic[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }
};

int main() {

    return 0;
}