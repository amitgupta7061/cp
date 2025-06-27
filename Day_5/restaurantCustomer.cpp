#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &time, unordered_map<int, int> map){
    sort(time.begin(), time.end());
    int result = INT_MIN, currCst = 0;
    for(int i = 0; i < time.size(); i++){
        currCst += map[time[i]];
        result = max(result, currCst);
    }
    return result;
}


int main() {

    int customer;
    cin>>customer;
    unordered_map<int, int> map;
    vector<int> time;
    for(int i = 0; i < customer; i++){
        int en, ex;
        cin>>en>>ex;
        map[en] = 1;
        map[ex] = -1;
        time.push_back(en);
        time.push_back(ex);
    }

    cout<<f(time, map);

    return 0;
}