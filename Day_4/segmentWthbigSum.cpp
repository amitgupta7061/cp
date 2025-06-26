#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int l = 0, r = 0;
    long long currSum = 0, result = 0;

    while(r < n){
        currSum += nums[r];
        while(currSum >= k){
            result += (n - r);
            currSum -= nums[l++];
        }
        r++;
    }

    cout<<result;

    return 0;
}