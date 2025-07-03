#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string s, string t, int l, int r){
        if(r == t.size()) return 1;
        if(l == s.size()) return 0;

        if(s[l] == t[r]){
            return f(s, t, l+1, r+1) + f(s, t, l+1, r);
        } else {
            return f(s, t, l+1, r+1);
        }
    }
    int numDistinct(string s, string t) {
        return f(s, t, 0, 0);
    }
};

int main() {

    return 0;
}