#include <bits/stdc++.h>
using namespace std;

void f(int n, string str){
    if(n == 0) return;
    cout<<str<<"\n";
    f(n - 1, str + '*');
}


int main() {

    f(5, "*");

    return 0;
}