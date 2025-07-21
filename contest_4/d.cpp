#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> name(n);
    for (int i = 0; i < n; i++) cin >> name[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);

    for (int i = 0; i < n - 1; i++) {
        string s = name[i], t = name[i + 1];
        bool found = false;
        int len = min(s.size(), t.size());
        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                int u = s[j] - 'a';
                int v = t[j] - 'a';
                adj[u].push_back(v);
                indegree[v]++;
                found = true;
                break;
            }
        }
        if (!found && s.size() > t.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    string order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order += (char)(u + 'a');
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if (order.size() < 26) {
        cout << "Impossible\n";
        return 0;
    }

    cout << order << "\n";
    return 0;
}
