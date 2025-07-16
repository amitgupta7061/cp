#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, 0))); // 0 = unknown, 1 = mouse wins, 2 = cat wins
        queue<tuple<int, int, int>> q;

        // Base cases
        for (int i = 0; i < n; ++i) {
            dp[0][i][1] = 1; // Mouse at 0 always wins
            dp[0][i][2] = 1;

            dp[i][i][1] = 2; // Cat catches mouse
            dp[i][i][2] = 2;

            q.emplace(0, i, 1);
            q.emplace(0, i, 2);
            q.emplace(i, i, 1);
            q.emplace(i, i, 2);
        }

        // Precompute degree
        vector<vector<vector<int>>> parent(n, vector<vector<int>>(n, vector<int>(3, 0)));
        for (int m = 0; m < n; ++m) {
            for (int c = 0; c < n; ++c) {
                parent[m][c][1] = graph[m].size();
                parent[m][c][2] = count_if(graph[c].begin(), graph[c].end(), [](int x) { return x != 0; });
            }
        }

        while (!q.empty()) {
            auto [m, c, t] = q.front(); q.pop();
            int res = dp[m][c][t];
            int prevTurn = 3 - t;

            vector<pair<int, int>> prevStates;
            if (t == 1) { // mouse moved, cat's turn next
                for (int pc : graph[c]) {
                    if (pc == 0) continue;
                    prevStates.emplace_back(m, pc);
                }
            } else { // cat moved, mouse's turn next
                for (int pm : graph[m]) {
                    prevStates.emplace_back(pm, c);
                }
            }

            for (auto& [pm, pc] : prevStates) {
                if (dp[pm][pc][prevTurn] != 0) continue;

                if ((res == 1 && prevTurn == 1) || (res == 2 && prevTurn == 2)) {
                    dp[pm][pc][prevTurn] = res;
                    q.emplace(pm, pc, prevTurn);
                } else {
                    parent[pm][pc][prevTurn]--;
                    if (parent[pm][pc][prevTurn] == 0) {
                        dp[pm][pc][prevTurn] = res;
                        q.emplace(pm, pc, prevTurn);
                    }
                }
            }
        }

        return dp[1][2][1];
    }
};


int main() {

    return 0;
}