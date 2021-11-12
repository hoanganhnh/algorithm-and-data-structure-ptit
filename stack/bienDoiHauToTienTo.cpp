#include<bits/stdc++.h>

using namespace std;

bool contain(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            return true;
    }
    return false;
}

string convert(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); i++) {
        if (contain(s[i])) {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string temp = s[i] + s2 + s1;
            st.push(temp);
        } else {
            st.push(string (1, s[i]));
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