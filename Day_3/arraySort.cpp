#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &nums, vector<pair<int, int>> &result, int temp){
    int n = nums.size();
    for(int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; ++j) {
            if(nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                swapped = true;
                result.push_back({temp, j+1});
            }
        }
        if (!swapped) break;
    }
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

        vector<pair<int, int>> result;
        bubbleSort(nums1, result, 1);
        bubbleSort(nums2, result, 2);
        
        for(int i = 0; i < n; i++){
            if(nums1[i] > nums2[i]){
                swap(nums1[i], nums2[i]);
                result.push_back({3, i+1});
            }
        }

        cout<<result.size()<<"\n";
        for(auto it : result){
            cout<<it.first<<" "<<it.second<<"\n";
        }
        
    }

    return 0;
}