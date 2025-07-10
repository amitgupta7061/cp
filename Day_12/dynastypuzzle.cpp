#include <bits/stdc++.h>
using namespace std;

int f(vector<string> &names, int ind, int ch, int st, vector<vector<vector<int>>> &dp){
    if(ind >= names.size()) {
        if(st != 26 && ch != 26 && st == ch) return 0;
        return INT_MIN;
    }

    if(dp[ind][ch][st] != -1) return dp[ind][ch][st];

    int take = INT_MIN, nottake = INT_MIN;

    if(ch == 26 || ch == (names[ind][0] - 'a')){
        int newch = names[ind].back() - 'a';
        int newst = (st == 26) ? (names[ind][0] - 'a') : st;
        int cur = names[ind].length();
        int rest = f(names, ind + 1, newch, newst, dp);
        if (rest != INT_MIN) take = cur + rest;
    }

    nottake = f(names, ind + 1, ch, st, dp);

    return dp[ind][ch][st] = max(take, nottake);
}


int f2(vector<string> &names, int &n){
    for(int i = 0; i < n; i++){
        
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for(int i = 0; i < n; i++) {
        cin >> names[i];
    }
    vector dp(n, vector(27, vector<int>(27, -1)));

    int result = f(names, 0, 26, 26, dp);

    cout << (result == INT_MIN ? 0 : result) << endl;

    return 0;
}
