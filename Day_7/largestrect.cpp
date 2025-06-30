#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> next_smaller(vector<int> &nums, int n){
        vector<int> nxt_sml(n);
        stack<int> st;
        nxt_sml[n-1] = n;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(st.size() > 0 and nums[st.top()] >= nums[i]) st.pop();
            if(st.size() == 0) nxt_sml[i] = n;
            else nxt_sml[i] = st.top();
            st.push(i);
        }
        return nxt_sml;
    }
    vector<int> prev_smaller(vector<int> &nums, int n){
        vector<int> prev_sml(n);
        stack<int> st;
        prev_sml[0] = -1;
        st.push(0);
        for(int i = 1; i < n; i++){
            while(st.size() > 0 and nums[i] <= nums[st.top()]) st.pop();
            if(st.empty()) prev_sml[i] = -1;
            else prev_sml[i] = st.top();
            st.push(i);
        }
        return prev_sml;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), max_area = -1;
        vector<int> nxt_sml = next_smaller(heights, n);
        vector<int> prv_sml = prev_smaller(heights, n);
        for(int i = 0; i < n; i++){
            int area = heights[i] * (nxt_sml[i] - prv_sml[i] - 1);
            max_area = max(area, max_area);
        }
        return max_area;
    }
};

int main() {

    return 0;
}