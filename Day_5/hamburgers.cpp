#include <bits/stdc++.h>
using namespace std;

bool can(vector<int> &have, vector<int> &price, vector<int> &need, long long mid, long long r){
    long long cost = 0;
    for (int i = 0; i < 3; ++i) {
        long long required = max(0LL, mid * 1LL * need[i] - have[i]);
        cost += required * price[i];
        if (cost > r) return false;
    }
    return cost <= r;
}


int main() {

    string s;
    cin>>s;

    vector<int> have(3), price(3), need(3);
    for(auto &it : have) cin>>it;
    for(auto &it : price) cin>>it;
    for(auto &ch : s){
        if(ch == 'B') need[0]++;
        else if(ch == 'S') need[1]++;
        else need[2]++;
    }

    long long r;
    cin>>r;

    long long  low = 0, high = 1e13, result = 0;

    while(low <= high){
        long long mid = low + (high - low) / 2LL;
        if(can(have, price, need, mid, r)){
            result = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }

    cout<<result;

    return 0;
}