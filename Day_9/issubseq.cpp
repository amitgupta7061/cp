#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size()) return false;
        int l = 0, r = 0;
        while(r < t.size()){
            if(l == s.size()) return true;
            if(s[l] == t[r]){
                l++; r++;
            } else{
                r++;
            }
        }
        if(l == s.size()) return true;
        else return false;
    }
};

int main() {

    return 0;
}