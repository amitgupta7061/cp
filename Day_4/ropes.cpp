#include <bits/stdc++.h>
using namespace std;

bool canCut(vector<int> &ropesLen, double target, int k){
    long long count = 0;
    for(auto len : ropesLen){
        count += (long long)(len / target);
    }
    return count >= k;
}

int main() {
    int numberOfRopes, k;
    cin >> numberOfRopes >> k;

    vector<int> ropesLen(numberOfRopes);
    for(int i = 0; i < numberOfRopes; i++){
        cin >> ropesLen[i];
    }

    double low = 0, high = 1e7, result = 0;

    for(int i = 0; i < 100; i++){
        double mid = (low + high) / 2.0;
        if(canCut(ropesLen, mid, k)){
            result = mid;
            low = mid;
        } else{
            high = mid;
        }
    }

    cout << fixed << setprecision(6) << result << "\n";
    return 0;
}
