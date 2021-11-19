#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s; 
        cin >> s;
        int n = s.length();
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            if (s[i] == 'I' || i == n) {
                cout << i + 1;
                while (!st.empty()) {
                    int top = st.top();
                    st.pop();
                    cout << top;
                }
            } else if (s[i] == 'D') {
                st.push(i + 1);
            }
        }
        cout << endl;
    }
}