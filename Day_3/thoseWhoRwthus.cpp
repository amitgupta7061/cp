#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &mat, int maxi){
    int m = mat.size(), n = mat[0].size();
    vector<int> rowCnt(m, 0), colCnt(n, 0);

    int maxiCnt = 0;    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == maxi){
                maxiCnt++;
                rowCnt[i]++; colCnt[j]++;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(rowCnt[i] + colCnt[j] - (mat[i][j] == maxi? 1 : 0) == maxiCnt){
                return maxi - 1;
            }
        }
    }
    return maxi;
}

int main() {

    int testCases;
    cin>>testCases;

    while(testCases--){
        int m, n;
        cin>>m>>n;
        int maxi = INT_MIN;
        vector<vector<int>> mat(m, vector<int>(n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cin>>mat[i][j];
                maxi = max(maxi, mat[i][j]);
            }
        }

        cout<<f(mat, maxi)<<"\n";
    }

    return 0;
}