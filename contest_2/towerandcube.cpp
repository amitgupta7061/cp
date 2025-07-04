#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;

    multiset<int> tower;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        auto it = tower.upper_bound(x);

        if(it != tower.end()) tower.erase(it);
        tower.insert(x);
    }

    cout<<tower.size();
    return 0;
}