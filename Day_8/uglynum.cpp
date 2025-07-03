#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<>> pq;
        unordered_set<long> visited;

        pq.push(1);
        visited.insert(1);
        long curr = 1;

        for(int i = 0; i < n; i++) {
            curr = pq.top(); pq.pop();

            if(visited.insert(curr * 2).second) pq.push(curr * 2);
            if(visited.insert(curr * 3).second) pq.push(curr * 3);
            if(visited.insert(curr * 5).second) pq.push(curr * 5);
        }

        return (int)curr;
    }
};


int main() {

    return 0;
}