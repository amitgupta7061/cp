#include <bits/stdc++.h>
using namespace std;


int main() {

    int r, b;
    cin>>r>>b;
    int dCnt = min(r, b), sCnt = 0;
    if(r < b){
        b = b - r;
        sCnt += (b / 2);
    } else{
        r = r - b;
        sCnt += (r / 2);
    }
    cout<<dCnt<<" "<<sCnt<<" ";
    return 0;
}