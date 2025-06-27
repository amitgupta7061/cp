#include <bits/stdc++.h>
using namespace std;

bool can(vector<int> &nums, long long mid, int k) {
    int count = 1;   
    long long currentSum = 0;

    for (auto num : nums) {
        if (currentSum + num > mid) {
            count++;           
            currentSum = num;  
        } else {
            currentSum += num;
        }
    }

    return count <= k;
}


long long f(vector<int> &nums, int k){
    long long low  = *max_element(nums.begin(), nums.end()); 
    long long high = accumulate(nums.begin(), nums.end(), 0LL);
    long long result = 0;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        if(can(nums, mid, k)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {

    int n, k;
    cin>>n>>k;

    vector<int> nums(n);
    for(auto &it : nums) cin>>it;

    cout<<f(nums, k);

    return 0;
}