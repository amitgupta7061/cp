#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(vector<int> &nums){
    int l = 0, r = nums.size() - 1;
    int dScore = 0, sScore = 0, chance = 1;
    while(l <= r){
        if(chance){ // sereja
            if(nums[l] >= nums[r]){
                sScore += nums[l++];
            } else{
                sScore += nums[r--];
            }
            chance = !chance;
        } else{
            if(nums[l] >= nums[r]){
                dScore += nums[l++];
            } else{
                dScore += nums[r--];
            }
            chance = !chance;
        }
    }
    return {sScore, dScore};
}


int main() {

    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    auto result = f(nums);
    cout<<result.first<<" "<<result.second;

    return 0;
}