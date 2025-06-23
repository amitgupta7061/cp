#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums){
    int minDiff = INT_MAX;

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - nums[i-1] < minDiff){
            minDiff = nums[i] - nums[i-1];
        }
    }
    if(minDiff < 0) return 0;
    return minDiff / 2 + 1;
}

int main() {
    int testCases;
    cin>>testCases;

    while(testCases--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin>>nums[i];
        }
        cout<<f(nums)<<"\n";
    }

    return 0;
}