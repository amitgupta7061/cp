#include <bits/stdc++.h>
using namespace std;

bool can(vector<int> &position, int mid, int cntofcow) {
    int startpos = position[0], cnt = 1;
    for (int i = 1; i < position.size(); i++) {
        if (position[i] - startpos >= mid) {
            cnt++;
            startpos = position[i];
        }
        if (cnt >= cntofcow) return true;
    }
    return false;
}

int f(vector<int> &position, int cntofcow) {
    sort(position.begin(), position.end());
    int low = 1, high = position.back() - position[0], ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can(position, mid, cntofcow)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int testcases;
    cin >> testcases;

    while (testcases--) {
        int n, c;
        cin >> n >> c;

        vector<int> position(n);
        for (auto &it : position) cin >> it;

        cout << f(position, c) << "\n";
    }

    return 0;
}
