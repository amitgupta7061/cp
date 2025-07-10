#include <bits/stdc++.h>
using namespace std;

int dp[101][101][11][11];
int MOD = 1e8;
int f(int fmen, int hmen, int &flimit, int &hlimit, int fcnt, int hcnt) {
    if (fmen < 0 or hmen < 0  or fcnt > flimit or hcnt > hlimit) return 0;
    if (fmen == 0 and hmen == 0) return 1;
    if (dp[fmen][hmen][fcnt][hcnt] != -1) return dp[fmen][hmen][fcnt][hcnt] % MOD;

    int ways = 0;
    if (fmen > 0 and fcnt < flimit)
        ways += (f(fmen - 1, hmen, flimit, hlimit, fcnt + 1, 0) % MOD);

    if (hmen > 0 and hcnt < hlimit)
        ways += (f(fmen, hmen - 1, flimit, hlimit, 0, hcnt + 1) % MOD);

    return dp[fmen][hmen][fcnt][hcnt] = ways % MOD;
}

int main() {
    int fmen, hmen, flimit, hlimit;
    cin >> fmen >> hmen >> flimit >> hlimit;
    memset(dp, -1, sizeof(dp));
    cout << f(fmen, hmen, flimit, hlimit, 0, 0) << endl;

    return 0;
}
