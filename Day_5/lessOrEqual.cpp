#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &ele : nums) cin >> ele;

    sort(nums.begin(), nums.end());

    if (k == 0) {
        if (nums[0] > 1) cout << nums[0] - 1;
        else cout << -1;
    } else if (k == n) {
        cout << nums[n - 1];
    } else {
        if (nums[k - 1] == nums[k]) cout << -1;
        else cout << nums[k - 1];
    }

    return 0;
}
