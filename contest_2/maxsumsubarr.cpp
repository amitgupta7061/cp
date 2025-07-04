#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> nums(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        prefix[i + 1] = prefix[i] + nums[i];
    }

    multiset<long long> window;
    long long maxSum = LLONG_MIN;

    for (int r = a; r <= n; r++) {
        window.insert(prefix[r - a]);

        if (r - b - 1 >= 0) {
            window.erase(window.find(prefix[r - b - 1]));
        }

        maxSum = max(maxSum, prefix[r] - *window.begin());
    }

    cout << maxSum << "\n";
    return 0;
}
