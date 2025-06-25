#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<char>> &grid, vector<vector<int>> &treeCnt){
    treeCnt[0][0] = grid[0][0] == '*' ? 1 : 0;
    int n = grid.size();

    for(int i = 1; i < n; i++){ // 1st col
        treeCnt[i][0] = treeCnt[i-1][0] + (grid[i][0] == '*');
    }
    for(int i = 1; i < n; i++){ // 1st row
        treeCnt[0][i] = treeCnt[0][i-1] + (grid[0][i] == '*');
    }

    for(int i = 1; i < n; i++){
        for(int j = 1 ; j < n; j++){
            treeCnt[i][j] = (grid[i][j] == '*') + treeCnt[i][j-1] + treeCnt[i-1][j] - treeCnt[i-1][j-1];
        }
    }
}

int main() {

    int n, q;
    cin>>n>>q;

    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>> treeCnt(n, vector<int>(n, 0));
    f(grid, treeCnt);

    while(q--){
        int x1, x2, y1, y2;
        cin>>y1>>x1>>y2>>x2;

        x1--; x2--; y1--; y2--;

        int result = treeCnt[y2][x2];
        if(y1 > 0) result -= treeCnt[y1-1][x2];
        if(x1 > 0) result -= treeCnt[y2][x1-1];
        if(x1 > 0 and y1 > 0) result += treeCnt[y1-1][x1-1];

        cout<<result<<"\n";

    }

    return 0;
}