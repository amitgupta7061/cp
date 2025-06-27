#include <bits/stdc++.h>
using namespace std;

bool canTake(vector<int> &nums, long long mid, int k){
    long long cnt = 0;
    for(auto it : nums){
        cnt += min((long long)it, mid);
    }
    return cnt >= (mid * k);
}


int main() {

    int k, n;
    cin>>k>>n;

    vector<int> nums(n);

    for(auto &it : nums) cin>>it;

    long long totalStudent = accumulate(nums.begin(), nums.end(), 0LL);
    long long low = 0, high = totalStudent / (long long)k;
    long long result = 0;

    while(low <= high){
        long long mid = low + (high - low) / 2;
        if(canTake(nums, mid, k)){
            result = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }

    cout<<result;

    return 0;
}