#include <bits/stdc++.h>

using namespace std;

void result(string s) {
    char c;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        if (c == '{' || c == '[' || c == '(') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == '{' && c == '}') {
                st.pop();
            } else if (!st.empty() && st.top() == '[' && c == ']') {
                st.pop();
            } if (!st.empty() && st.top() == '(' && c == ')') {
                st.pop();
            }
        }
    }
    if (st.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s; 
        cin >> s;
        result(s);
        cout << endl;
    }
}