#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp; string result = "";
        for(auto ch : s) mp[ch]++;
        priority_queue<pair<int, char>> pq;
        for(auto it : mp) pq.push({it.second, it.first});
        while(pq.size()){
            auto it = pq.top(); pq.pop();
            for(int i = 0; i < it.first; i++) result += it.second;
        }
        return result;
    }
};

int main() {

    return 0;
}