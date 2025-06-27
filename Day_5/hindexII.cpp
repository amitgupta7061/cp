#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can(vector<int>& citations, int mid) {
        int cnt = 0;
        for(auto ele : citations){
            if(ele >= mid) cnt++;
        }
        return cnt >= mid;
    }

    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size();
        int result = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(can(citations, mid)){
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};


int main() {

    return 0;
}