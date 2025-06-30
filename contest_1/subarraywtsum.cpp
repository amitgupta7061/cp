#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> nums(n);
    for (auto &it : nums) cin >> it;

    unordered_map<long long, int> map;
    map[0] = 1;

    long long sum = 0;
    int cnt = 0;
    for (auto it : nums) {
        sum += it;
        if (map.count(sum - x)) {
            cnt += map[sum - x];
        }
        map[sum]++;
    }

    cout << cnt;
    return 0;
}
