#include <bits/stdc++.h>
using namespace std;

string f(string &str){
    int mid = (str.size() + 1) / 2 - 1;
    string result(1, str[mid]);
    int l = mid - 1, r = mid + 1;
    bool chance = true;

    while(l >= 0 && r < str.size()){
        if(chance){
            result += str[r++];
        } else{
            result += str[l--];
        }
        chance = !chance;
    }

    while(l >= 0) result += str[l--];
    while(r < str.size()) result += str[r++];

    return result;
}

int main() {
    string str;
    cin >> str;
    cout << f(str);
    return 0;
}
