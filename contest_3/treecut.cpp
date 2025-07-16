#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> dp;
int f(vector<pair<int, int>> trees, int  ind, int last) {
    if (ind == trees.size()) return 0;

    auto key = make_pair(ind, last);
    if (dp.count(key)) return dp[key];

    int x = trees[ind].first, h = trees[ind].second;

    int ans = f(trees, ind + 1, x);
    if (x - h > last)
        ans = max(ans, 1 + f(trees, ind + 1, x));
    if (ind == trees.size() - 1 || x + h < trees[ind + 1].first)
        ans = max(ans, 1 + f(trees, ind + 1, x + h));

    return dp[key] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> trees(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i].first >> trees[i].second;

    cout << f(trees, 0, INT_MIN) << endl;
    return 0;
}
