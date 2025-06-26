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

    int l = 0, r = 0, result = INT_MAX;
    long long currSum = 0;

    while(r < n){
        currSum += nums[r];
        while(currSum >= k){
            result = min(result, r - l + 1);
            currSum -= nums[l++];
        }
        r++;
    }

    if(result == INT_MAX)
        cout << "-1";
    else
        cout << result;


    return 0;
}