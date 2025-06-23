#include <bits/stdc++.h>
using namespace std;

void f(int num){
    int base = 1;
    vector<int> arr;
    while(num--){
        int ld = num % 10;
        if(ld != 0){
            arr.push_back(base * ld);
        }
        base *= 10;
    }
    cout<<arr.size()<<"\n";
    for(auto it :  arr) cout<<it<<" ";
    cout<<"\n";
}

int main() {

    int numOfTest;
    cin>>numOfTest;

    while(numOfTest--){
        int num;
        cin>>num;
        f(num);
    }

    return 0;
}