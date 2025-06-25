#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums1, vector<int> &nums2){

}

int main() {

    int testCases;
    cin>>testCases;

    while(testCases--){
        int n;
        cin>>n;
        
        vector<int> nums1(n), nums2(n);
        for(int i = 0; i < n; i++) cin>>nums1[i];
        for(int i = 0; i < n; i++) cin>>nums2[i];

        f(nums1, nums2);
    }

    return 0;
}