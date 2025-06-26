#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin>>n>>k;

    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int l = 0, r = 0;
    long long currSum = 0, result = 0;

    long long mini = LLONG_MAX, maxi = LLONG_MIN;

    while(r < n){
        mini = min(mini, nums[r]);
        maxi = max(maxi, nums[r]);

        while(maxi - mini <= k){
            result += (n - r);
        }
    }
    cout<<result;

    return 0;
}