#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubarray(vector<int>& nums) {
    int n = nums.size(), ans = 1;

    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1])
            left[i] = left[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1])
            right[i] = right[i + 1] + 1;
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, left[i]);

    for (int i = 1; i < n - 1; ++i) {
        if (nums[i - 1] < nums[i + 1])
            ans = max(ans, left[i - 1] + right[i + 1]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& x : nums) cin >> x;
    cout << longestIncreasingSubarray(nums) << endl;
    return 0;
}
