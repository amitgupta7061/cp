#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(q.size()){
            int currroom = q.front(); q.pop();
            
            for(auto &havingkey : rooms[currroom]){
                if(!visited[havingkey]){
                    q.push(havingkey);
                }
            }
        }
        for(auto it : visited) if(!it) return false;
        return true;
    }
};

int main() {

    return 0;
}