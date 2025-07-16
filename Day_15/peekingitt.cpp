#include <bits/stdc++.h>
using namespace std;

class Iterator {
    struct Data;
	Data* data;
public:
    Iterator(const vector<int>& nums);
        Iterator(const Iterator& iter);
        
    int next();
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    vector<int> nums; 
    int ind = 0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        this->nums = nums;
        this->ind = 0;
	}
	
	int peek() {
        if(ind >= nums.size()) return -1;
        return nums[ind];
	}
	
	int next() {
	    if(ind >= nums.size()) return -1;
        int x = nums[ind];
        ind++;
        return x;
	}
	
	bool hasNext() const {
	    return ind < nums.size();
	}
};

int main() {

    return 0;
}