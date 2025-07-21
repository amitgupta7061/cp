#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void f(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    visited[r][c] = true;

    for (auto it : directions) {
        int nr = r + it.first, nc = c + it.second;

        if(nr >= 0 and nc >= 0 and nr < grid.size() and nc < grid[0].size() and 
            !visited[nr][nc] and grid[nr][nc] == '.'){
            f(nr, nc, grid, visited);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    

    for(int i = 0; i < m; i++){
        for(int j = 0 ; j < n; j++){
            cin>>grid[i][j];
        }
    }

    int conn = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                f(i, j, grid, visited);
                conn++;
            }
        }
    }

    cout << conn << endl;
    return 0;
}
