#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    while (testcases--) {
        int n, q;
        cin >> n >> q;

        vector<int> sugar(n);
        for (auto &it : sugar) cin >> it;

        sort(sugar.rbegin(), sugar.rend());

        vector<int> prefix(n);
        prefix[0] = sugar[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + sugar[i];
        }

        while (q--) {
            int x;
            cin >> x;

            int low = 0, high = n - 1, ans = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (prefix[mid] >= x) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            cout << (ans == -1 ? -1 : ans + 1) << "\n";
        }
    }

    return 0;
}
