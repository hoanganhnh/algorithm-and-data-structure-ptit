#include <bits/stdc++.h>

using namespace std;

void resolve(string s) {/* c1 */
    stack<char> st;

    for (char x: s) {
        if (x == '(' || x == ')' && st.empty()) {
            st.push(x);
        } else if (x == ')') {
            if (st.top() == '(' && !st.empty()) {
                st.pop();
            } else {
                st.push(x);
            }
        }
    }
    int d1= 0, d2 = 0;
    while (!st.empty()) {
        if (st.top() == '(') {
            d1++;
        } else {
            d2++;
        }
        st.pop();
    }
    int res = d1 / 2 + d2 / 2 + d1 % 2 + d2 % 2;
    cout << res;
}

int solve(string s) {/* c2 */
    stack<char> st;
    int cnt = 0;
    for (char x: s) {
        if (x == '(') {
            st.push(x);
        } else {
            if (!st.empty()) {
                st.pop();
            } else {
                st.push('(');
                cnt++;
            }
        }
    }
    return cnt + st.size() / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}