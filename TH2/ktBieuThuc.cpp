#include <bits/stdc++.h>
using namespace std;

string detroyCharacter(string s) {
    stack<char> st;
    string res = "";
    for (int i; i < s.length(); i++) {
        if (s[i] == '(') {
            char c = s[i - 1];
            if (c == '-' || c == '+') {
                st.push(c);
            }
            if (c == '(' && !st.empty()) {
                st.push(st.top());
            }
        }
        if (!st.empty() && st.top() == '-') {
            if (s[i] == '-') {
                s[i] = '+';
            } else if (s[i] == '+') {
                s[i] = '-';
            }
        }
        if (s[i] == ')' && !st.empty()) {
            st.pop();
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == ')') {
            continue;
        }
        res += string(1, s[i]);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (detroyCharacter(s1) == detroyCharacter(s2)) {
            cout << 1;
        } else {
            cout << 0;
        }
        cout << endl;
    }
}