#include <bits/stdc++.h>
using namespace std;


int f(int a, int b){
    if(b == 0) return a;
    return f(b, a % b);
}

int main() {
    f(10, 8);
    return 0;
}

