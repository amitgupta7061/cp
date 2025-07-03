#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    double sum; 
    int cnt;
    MedianFinder() {
        sum = 0; cnt = 0;
    }
    
    void addNum(int num) {
        sum += num * 1.0;
        cnt++;
    }
    
    double findMedian() {
        return sum / (cnt*1.0);
    }
};


int main() {

    return 0;
}