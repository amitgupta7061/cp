#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        for(int i = 0; i < s.length(); i++){
            if(result.length() >= 2){
                int n = result.length();
                if(result[n-1] == result[n-2] and result[n-1] == s[i]) continue;
                else result.push_back(s[i]);
            } else result.push_back(s[i]);
        }
        return result;
    }
};

int main() {

    return 0;
}