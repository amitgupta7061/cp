#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> songs(n);
    for (auto &it : songs) cin >> it;

    unordered_map<int, int> map;
    int l = 0, r = 0, result = 0;

    while (r < n) {
        map[songs[r]]++;

        while (map[songs[r]] > 1) {
            map[songs[l]]--;
            l++;
        }

        result = max(result, r - l + 1);
        r++;
    }

    cout << result << endl;
    return 0;
}
