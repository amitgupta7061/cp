    #include <bits/stdc++.h>
    using namespace std;

    bool can(vector<int> &task, int worker, int mid) {
        vector<int> count(worker + 1, 0);
        for (auto it : task) count[it]++;

        long long total = 0;
        for (int i = 1; i <= worker; i++) {
            int proficient = min(count[i], mid);    
            int lefttime = mid - proficient;      
            int notleft = lefttime / 2;           
            total += 1LL * proficient + notleft;     
        }

        return total >= (long long)task.size();     
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int testcases;
        cin >> testcases;

        while (testcases--) {
            int m, n;
            cin >> m >> n;

            vector<int> task(n);
            for (auto &it : task) cin >> it;

            int low = 0, high = 2 * n, ans = 0;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (can(task, m, mid)) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            cout << ans << '\n';
        }

        return 0;
    }
