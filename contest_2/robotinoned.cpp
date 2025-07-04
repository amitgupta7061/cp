#include <bits/stdc++.h>
using namespace std;

struct Robot {
    int pos, idx;
    char dir;
};

void solve_case() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int &i : x) cin >> i;

    string s;
    cin >> s;

    vector<int> ans(n, -1);
    vector<Robot> even, odd;
    for (int i = 0; i < n; ++i) {
        Robot r = {x[i], i, s[i]};
        if (x[i] % 2 == 0) even.push_back(r);
        else odd.push_back(r);
    }

    auto process = [&](vector<Robot> &group) {
        sort(group.begin(), group.end(), [](Robot &a, Robot &b) {
            return a.pos < b.pos;
        });

        stack<Robot> stk;
        map<int, int> tmpAns;

        for (Robot &r : group) {
            if (r.dir == 'R') {
                stk.push(r);
            } else {
                if (!stk.empty()) {
                    Robot left = stk.top(); stk.pop();
                    int t = (r.pos - left.pos) / 2;
                    ans[r.idx] = ans[left.idx] = t;
                } else {
                    
                    stk.push({-r.pos, r.idx, 'R'});
                }
            }
        }

        vector<Robot> remain;
        while (!stk.empty()) {
            remain.push_back(stk.top());
            stk.pop();
        }
        reverse(remain.begin(), remain.end());

        for (int i = 1; i < remain.size(); i += 2) {
            Robot a = remain[i-1];
            Robot b = remain[i];
            int t = (b.pos - a.pos) / 2;
            ans[a.idx] = ans[b.idx] = t;
        }
    };

    process(even);
    process(odd);

    for (int a : ans) cout << (a == -1 ? -1 : a) << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve_case();
    return 0;
}
