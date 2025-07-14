#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int f(vector<vector<int>> &mat, int r, int c, vector<vector<int>> &dp){
        if(dp[r][c] != -1) return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int maxi = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxi = max(maxi, f(matrix, i, j, dp));
            }
        }
        return maxi;
    }
};

int main() {

    return 0;
}
