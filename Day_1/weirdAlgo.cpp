#include <bits/stdc++.h>
using namespace std;

void f(long long num){
    while(num != 1){
        cout<<num<<" ";
        if(num % 2) num = (num * 3ll) + 1ll;
        else num /= 2ll;
    }
    cout<<num;
}
int main() {

    int n;
    cin>>n;
    f(n);

    return 0;
}