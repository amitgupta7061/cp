#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (st.size() && temperatures[st.top()] < temperatures[i]) {
                int prevdayInd = st.top(); st.pop();
                result[prevdayInd] = i - prevdayInd;
            }
            st.push(i);
        }
        return result;
    }
};

int main() {

    return 0;
}