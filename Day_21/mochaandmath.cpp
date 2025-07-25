#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums){
    int result = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        result &= nums[i];
    }
    return result;
}

int main() {
    int testcases;
    cin >> testcases;

    while(testcases--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int &num : nums) cin >> num;

        cout << f(nums) << endl;
    }

    return 0;
}
