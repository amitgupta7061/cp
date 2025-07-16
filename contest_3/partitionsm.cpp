#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int canPartition(int n) {
    int total = n * (n + 1) / 2;
    if (total % 2 != 0) return 0;

    int target = total / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int sum = 0; sum <= target; ++sum) {
            dp[i][sum] = (dp[i - 1][sum] % MOD);
            if (sum >= i) {
                dp[i][sum] += (dp[i - 1][sum - i] % MOD); 
            }
        }
    }

    return (dp[n][target] / 2) % MOD;
}

int main() {
    int n;
    cin >> n;
    cout << canPartition(n) << endl;
    return 0;
}
