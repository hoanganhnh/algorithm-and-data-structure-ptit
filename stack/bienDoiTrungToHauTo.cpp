#include<bits/stdc++.h>

using namespace std;
/*
    @FIXME
*/


string convert(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isContain(s[i])) {
            string first = st.top();
            st.pop();
            string t = first + s[i];
            st.push(t);
        } else if (!checkNgoac(s[i])) {
            if (st.empty()) {
                st.push(string (1, s[i])); /*convert char -> string*/
            } else {
                string second = st.top();
                st.pop();
                string t = s[i] + second;
                st.push(t);
            }
        }
    }
    return st.top();
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
