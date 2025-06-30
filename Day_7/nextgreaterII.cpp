#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nge(vector<int> &nums){
        int n = nums.size();
        vector<int> result(n); result[n-1] = nums[n-1];
        stack<int> st; st.push(nums[n-1]);
        for(int i = n-2; i >= 0; i--){
            while(st.size() and st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()) result[i] = -1;
            else result[i] = st.top();
            st.push(nums[i]);
        }
        return result;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> newnums = nums;
        newnums.insert(newnums.end(), nums.begin(), nums.end()); 
        vector<int> result = nge(newnums);
        return vector<int>(result.begin(), result.begin() + result.size() / 2);
    }
};

int main() {

    return 0;
}