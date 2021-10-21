#include<bits/stdc++.h>

using namespace std;

bool isContain(char s) {
    switch (s) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return true;
    }
    return false;
}

string convert(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isContain(s[i])) {
            string first = st.top();
            st.pop();
            string  second = st.top();
            st.pop();
            string t =  first + second + s[i];
            st.push(t);
        } else {
            st.push(string (1, s[i])); /*convert char -> string*/
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
