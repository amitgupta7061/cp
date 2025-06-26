#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums1, vector<int> &nums2){
    int m = nums1.size(), n = nums2.size();
    vector<int> result(n, 0);
    int i = 0, j = 0, smallerCnt = 0;
    while(j < n){
        while(i < m and nums1[i] < nums2[j]){
            smallerCnt++;
            i++;
        }
        result[j] = smallerCnt;
        j++;
    }

    for(auto it : result) cout << it << " ";
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);

    for(int i = 0; i < m; i++) cin >> nums1[i];
    for(int i = 0; i < n; i++) cin >> nums2[i];

    f(nums1, nums2);

    return 0;
}
