#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &nums, int k) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upper_bound(vector<int> &nums, int k) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}



int main() {

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());

    int query;
    cin>>query;

    while(query--){
        int num1, num2;
        cin>>num1>>num2;

        int left = lower_bound(nums, num1);
        int rght = upper_bound(nums, num2);

        cout<<rght - left<<"\n";
    }

    return 0;
}