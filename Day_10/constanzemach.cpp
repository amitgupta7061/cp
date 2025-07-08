#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long f(string &s, int ind, vector<long long> &dp){
    if(ind == s.size()) return 1LL;
    if(s[ind] == 'w' or s[ind] == 'm') return 0LL;
    if(dp[ind] != -1) return dp[ind] % MOD;

    long long cnt = f(s, ind+1, dp);
    // both element case
    if(ind + 1 < s.size() and s[ind] == s[ind+1] and (s[ind] == 'u' or s[ind] == 'n')){
        cnt += f(s, ind + 2, dp);
    }
    return dp[ind] = cnt % MOD;
}

int main() {
    string s;
    cin>>s;
    vector<long long> dp(s.size(), -1);
    cout<<f(s, 0, dp);
    return 0;
}