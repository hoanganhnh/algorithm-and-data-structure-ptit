#include<bits/stdc++.h>

using namespace std;

int oprt(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

string convert(string s) {
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else if (s[i] == '(') {
            st.push('(');
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            while (!st.empty() && oprt(s[i]) <= oprt(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        } else {
            res += s[i];
        }
    }
    while (!st.empty()) {
        if (st.top() != '(') {
            res += st.top();
        }
        st.pop();
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
       string s;
       cin >> s;
       cout << convert(s) << endl;
    }
}
