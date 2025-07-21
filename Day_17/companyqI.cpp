#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int parent[200005][20];

    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        parent[i][0] = boss; 
    }

    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j-1] != 0)
                parent[i][j] = parent[parent[i][j-1]][j-1];
            else
                parent[i][j] = 0;
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < 20; ++i) {
            if (k & (1 << i)) {
                
                x = parent[x][i];
                if (x == 0) break;
            }
        }
        cout << (x == 0 ? -1 : x) << '\n';
    }

    return 0;
}
