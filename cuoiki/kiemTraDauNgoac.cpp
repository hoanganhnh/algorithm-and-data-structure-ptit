#include <bits/stdc++.h>

using namespace std;

void resole(string s) {
    char c;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        if (st.empty() && c == ')' || st.empty() && c == ']' || st.empty() && c == '}') {
            cout << "false";
            return;
        } else {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(' && c == ')') {
                    st.pop();
                } else if (!st.empty() && st.top() == '[' && c == ']') {
                    st.pop();
                } else if (!st.empty() && st.top() == '{' && c == '}') {
                    st.pop();
                }
            }
        }
    }

    if (st.empty()) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        resole(s);
    }
}