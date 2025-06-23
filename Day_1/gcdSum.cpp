#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long num){
    long long sum = 0;
    while(num){
        sum += (long long)num % 10;
        num /= 10;
    } 
    return sum;
}

int main() {
    int testCases;
    cin >> testCases;

    while(testCases--){
        long long num;
        cin >> num;
        
        while(true){
            long long sNum = digitSum(num);
            if(__gcd(num, sNum) > 1){
                cout << num << endl;
                break;
            }
            num++;
        }
    }

    return 0;
}
