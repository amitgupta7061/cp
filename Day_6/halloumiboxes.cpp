#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &nums){
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < nums[i-1]) return false;
    }
    return true;
}

int main() {

    int testcases;
    cin>>testcases;

    while(testcases--){
        int n, k;
        cin>>n>>k;

        vector<int> nums(n);
        for(auto &el : nums) cin>>el;

        if(k >= 2){
            cout<<"YES\n";
        } else{
            if(isSorted(nums)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}