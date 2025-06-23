#include <bits/stdc++.h>
using namespace std;


int main() {
    int testCases;
    cin>>testCases;

    while(testCases--){
        vector<bool> freq(26, false);
        string str;
        cin>>str;
        for(int i = 0; i < str.size(); ++i){
            if(freq[str[i] - 'a']){
                cout<<"Yes";
                return 0;
            }
            freq[str[i] - 0] = true;
        }
        cout<<"No";
    }
    return 0;
}