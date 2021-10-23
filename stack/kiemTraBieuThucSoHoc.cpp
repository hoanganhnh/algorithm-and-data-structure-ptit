#include<bits/stdc++.h>

using namespace std;

bool resolve(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ')') {
            st.push(s[i]);
        } else {
            bool check = false;
            while (st.top() != '(') {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    check = true;
                }
                st.pop();
            }
            st.pop();
            if (!check) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        if (resolve(s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}