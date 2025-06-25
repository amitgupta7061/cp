#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int i = 1; i < nums.size(); i++)
            arr[i] = arr[i] +  arr[i-1];
    }
    
    int sumRange(int left, int right) {
        return arr[right] - (left == 0 ? 0 : arr[left-1]);
    }
};


int main() {

    return 0;
}