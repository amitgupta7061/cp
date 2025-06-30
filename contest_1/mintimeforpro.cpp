#include <bits/stdc++.h>
using namespace std;

bool canMake(long long mid, vector<int>& time, int t) {
    long long total = 0;
    for (auto it : time) {
        total += mid / it;
        if (total >= t) return true;
    }
    return false;
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> time(n);
    for (auto &it : time) cin >> it;

    long long low = 1;
    long long high = 1LL * (*min_element(time.begin(), time.end())) * t;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canMake(mid, time, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
