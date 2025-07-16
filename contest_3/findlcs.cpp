#include <bits/stdc++.h>
using namespace std;

vector<int> findlcs(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    vector<int> lcs;
    while (i > 0 && j > 0) {
        if (nums1[i - 1] == nums2[j - 1]) {
            lcs.push_back(nums1[i - 1]);
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {

    int m, n;
    cin>>m>>n;

    vector<int> nums1(m), nums2(n);

    for(auto &it : nums1) cin>>it;
    for(auto &it : nums2) cin>>it;

    vector<int> result = findlcs(nums1, nums2);

    cout<<result.size()<<"\n";
    for(auto it : result) cout<<it<<" ";


    return 0;
}