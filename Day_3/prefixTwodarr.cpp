#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>> &mat, vector<vector<int>> &prefix){
    int m = mat.size(), n = mat[0].size();
    prefix[0][0] = mat[0][0];
    for(int i = 1; i < m; i++){ // 1st col
        prefix[i][0] = prefix[i-1][0] + mat[i][0];
    }
    for(int i = 1; i < n; i++){ // 1st row
        prefix[0][i] = prefix[0][i-1] + mat[0][i];
    }

    for(int i = 1; i < m; i++){
        for(int j = 1 ; j < n; j++){
            prefix[i][j] = mat[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        }
    }
}

int main() {

    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    vector<vector<int>> result(mat.size(), vector<int>(mat[0].size()));
    f(mat, result);

    for(auto &vect : result){
        for(auto el : vect) cout<<el<<" ";
        cout<<endl;
    }

    return 0;
}