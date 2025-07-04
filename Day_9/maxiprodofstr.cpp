#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getmask(string &s) {
        int mask = 0;
        for (char ch : s) {
            mask |= (1 << (ch - 'a'));
        }
        return mask;
    }
    int maxProduct(vector<string>& words) {
        int result = 0, n = words.size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((getmask(words[i]) & getmask(words[j])) == 0){
                    int m = words[i].size(), n = words[j].size();
                    result = max(result, m*n);
                }
            }
        }

        return  result;
    }
};

int main() {

    return 0;
}