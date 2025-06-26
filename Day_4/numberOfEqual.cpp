#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums1, vector<int> &nums2){
    int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0, finalCnt = 0;
    
    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            i++;
        }
        else if(nums1[i] > nums2[j]){
            j++;
        }
        else{
            int val = nums1[i];
            int cnt1 = 0, cnt2 = 0;
            while(i < m && nums1[i] == val) cnt1++, i++;
            while(j < n && nums2[j] == val) cnt2++, j++;
            finalCnt += cnt1 * cnt2;
        }
    }
    return finalCnt;
}


int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);

    for(int i = 0; i < m; i++) cin >> nums1[i];
    for(int i = 0; i < n; i++) cin >> nums2[i];

    cout<<f(nums1, nums2);

    return 0;
}
