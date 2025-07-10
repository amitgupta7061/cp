#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freetime;
        int n = startTime.size();
        freetime.push_back(startTime[0]);
        for(int i = 1; i < n; i++){
            freetime.push_back(startTime[i] - endTime[i-1]);
        }
        freetime.push_back(eventTime - endTime.back());

        int currsum = 0, maxi = 0, l = 0, r = 0;
        while(r < n){
            currsum += freetime[r];
            while(r - l + 1 > 2){
                currsum -= freetime[l];
                l++;
            }
            maxi = max(currsum, maxi);
        }
        return maxi;
    }
};

int main() {

    return 0;
}