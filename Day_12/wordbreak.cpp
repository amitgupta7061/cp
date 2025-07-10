#include <bits/stdc++.h>
using namespace std;

bool f(string &s, unordered_set<string> &dict, int ind, vector<int> &dp) {
    if (ind == s.length()) return true;
    if (dp[ind] != -1) return dp[ind];
    if(dict.count(s)) return true;

    string word = "";
    for (int i = ind; i < s.size(); i++) {
        word += s[i];
        if (dict.count(word)) {
            if (f(s, dict, i + 1, dp)) return dp[ind] = true;
        }
    }
    return dp[ind] = false;
}

int wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict(B.begin(), B.end());
    vector<int> dp(A.size(), -1);
    return f(A, dict, 0, dp);
}


class Solution{
public:
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> dict(B.begin(), B.end());
        int n = A.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        int maxLen = 0;
        for (string &word : B)
            maxLen = max(maxLen, (int)word.length());

        for (int i = 1; i <= n; i++) {
            for (int j = max(0, i - maxLen); j < i; j++) {
                if (dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};


int main() {

    return 0;
}