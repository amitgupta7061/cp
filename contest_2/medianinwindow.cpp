#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder(int k) : windowSize(k), smallSize(0), largeSize(0) {}

    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        rebalanceHeaps();
    }

    void removeNum(int num) {
        delayed[num]++;
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        rebalanceHeaps();
    }

    int findMedian() {
        if (windowSize & 1) {
            return small.top();
        } else {
            return (small.top() + large.top()) / 2;
        }
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;
    int smallSize, largeSize;
    int windowSize;

    template <typename T>
    void prune(T& heap) {
        while (!heap.empty() && delayed[heap.top()]) {
            if (--delayed[heap.top()] == 0) {
                delayed.erase(heap.top());
            }
            heap.pop();
        }
    }

    void rebalanceHeaps() {
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }
};

vector<int> f(vector<int>& nums, int k) {
    MedianFinder finder(k);
    for (int i = 0; i < k; ++i) {
        finder.addNum(nums[i]);
    }
    vector<int> medians = {finder.findMedian()};
    for (int i = k; i < nums.size(); ++i) {
        finder.addNum(nums[i]);
        finder.removeNum(nums[i - k]);
        medians.push_back(finder.findMedian());
    }
    return medians;
}


int main() {

    int n, k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    vector<int> result = f(nums, k);
    for(auto it : result) cout<<it<<" ";

    return 0;
}