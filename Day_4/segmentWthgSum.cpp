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

    int l = 0, r = 0, result = 0;
    long long currSum = 0;

    while(r < n){
        if(currSum + nums[r] <= k){
            currSum += nums[r++];
            result = max(result, r - l);
        } else {
            currSum -= nums[l++];
        }  
    }
    result = max(result, r - l);
    cout<<result;

    return 0;
}