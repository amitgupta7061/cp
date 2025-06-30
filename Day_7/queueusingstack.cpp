#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> st;
    stack<int> hp;

public:
    MyQueue() {
    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
        } else {
            while (!st.empty()) {
                hp.push(st.top());
                st.pop();
            }
            st.push(x);
            while (!hp.empty()) {
                st.push(hp.top());
                hp.pop();
            }
        }
    }

    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};

int main() {

    return 0;
}