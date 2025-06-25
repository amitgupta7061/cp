#include <bits/stdc++.h>
using namespace std;


int main() {
    int testCases;
    cin>>testCases;

    while(testCases--){
        vector<bool> freq(26, false);
        int n;
        cin>>n;
        vector<char> str(n);

        for(int i = 0; i < n ; i++){
            cin>>str[i];
        }
        bool flag = false;
        for(int i = 0; i < str.size() - 1; ++i){
            if(freq[str[i] - 'a']){
                cout<<"Yes\n";
                flag = true;
                break;
            }
            freq[str[i] - 'a'] = true;
        }
        if(!flag){
            if(freq[str[n-1] - 'a'] and str.back() != str[0]) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}


