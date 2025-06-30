#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long exp = power(b, c, MOD - 1);

        long long result = power(a, exp, MOD);

        cout << result << '\n';
    }

    return 0;
}
