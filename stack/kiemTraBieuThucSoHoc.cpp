#include<bits/stdc++.h>

using namespace std;

bool resolve(string s) { /* c1 */
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

int check(string s) { /* c2 */
    stack<int> st;
    int j;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
                j = st.top();
                st.pop();

                if (i - j == 2) {
                    return 1;
                } else if (s[j + 1] == '(' && s[i - 1] == ')') {
                    return 1;
                }
            }
        
    }
    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        if (check(s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}