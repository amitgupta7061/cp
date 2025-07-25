#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removePairs(string& s, char first, char second, int gain) {
        stack<char> st;
        int score = 0;

        for (char ch : s) {
            if (!st.empty() && ch == second && st.top() == first) {
                st.pop();
                score += gain;
            } else {
                st.push(ch);
            }
        }
        s.clear();
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());

        return score;
    }
    int maximumGain(string s, int x, int y) {
        if (x > y) {
            return removePairs(s, 'a', 'b', x) + removePairs(s, 'b', 'a', y);
        } else {
            return removePairs(s, 'b', 'a', y) + removePairs(s, 'a', 'b', x);
        }
    }
};


int main() {

    return 0;
}