#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch == '(' or ch == '{' or ch == '[') st.push(ch);
            else {
                if(ch == ')'){
                    if(st.size() and st.top() == '(') st.pop();
                    else return false;
                } else if(ch == '}'){
                    if(st.size() and st.top() == '{') st.pop();
                    else return false;
                } else{
                    if(st.size() and st.top() == '[') st.pop();
                    else return false;
                }
            }
        }
        return st.size() == 0;
    }
};

int main() {

    return 0;
}