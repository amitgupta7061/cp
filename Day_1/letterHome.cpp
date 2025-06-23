#include <bits/stdc++.h>
using namespace std;


int main() {

    int t;
    cin>>t;
    while(t--){
        int n, s;
        cin>>n>>s;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin>>nums[i];
        }

        cout<<(nums[n-1]-nums[0]) + (min(abs(s - nums[0]), abs(nums[n-1] - s)))<<"\n";
    }

    return 0;
}