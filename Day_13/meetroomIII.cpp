#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pairr = pair<long long, int>;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> cntusedroom(n);

        priority_queue<int, vector<int>, greater<>> freeroom; 
        for (int i = 0; i < n; i++) freeroom.push(i);

        priority_queue<pairr, vector<pairr>, greater<>> ongoing;
        
        for (auto &meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!ongoing.empty() && ongoing.top().first <= start) {
                freeroom.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!freeroom.empty()) {
                int room = freeroom.top(); freeroom.pop();
                ongoing.push({end, room});
                cntusedroom[room]++;
            } else {
                auto [earliestEnd, room] = ongoing.top(); ongoing.pop();
                long long duration = end - start;
                long long newEnd = earliestEnd + duration;
                ongoing.push({newEnd, room});
                cntusedroom[room]++;
            }
        }

        int maxmeetings = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (cntusedroom[i] > maxmeetings) {
                maxmeetings = cntusedroom[i];
                ans = i;
            }
        }
        return ans;
    }
};


int main() {

    return 0;
}