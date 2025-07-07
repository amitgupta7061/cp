#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind, string &s, vector<int>& dp) {
        if (ind == s.size()) return 1;
        if (s[ind] == '0') return 0;
        if (dp[ind] != -1) return dp[ind];

        int count = f(ind + 1, s, dp);

        if (ind + 1 < s.size()) {
            int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');
            if (num >= 10 && num <= 26) {
                count += f(ind + 2, s, dp);
            }
        }

        return dp[ind] = count;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
};



int main() {

    return 0;
}