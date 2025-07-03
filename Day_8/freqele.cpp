#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto a : arr) m[a]++;
        vector<int> ans;
        for(int i = 0;i < k; i++){
            int mx = INT_MIN, x = 0;
            for(auto a : m){
                int temp = a.first;
                if(m[temp] > mx){
                    mx = m[temp];
                    x = temp;
                }
            }
            ans.push_back(x);
            m.erase(x);
        }
        return ans;
    }
};

int main() {

    return 0;
}