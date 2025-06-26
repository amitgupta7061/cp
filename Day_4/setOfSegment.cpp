#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int l = 0;
    long long result = 0;
    unordered_map<int, int> freq;

    for (int r = 0; r < n; r++) {
        freq[nums[r]]++;

        while (freq.size() > k) {
            freq[nums[l]]--;
            if (freq[nums[l]] == 0) {
                freq.erase(nums[l]);
            }
            l++;
        }

        result += (r - l + 1); 
    }

    cout << result;
    return 0;
}
