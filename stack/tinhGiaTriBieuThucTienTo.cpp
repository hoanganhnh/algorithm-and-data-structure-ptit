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

int caculator(int first, int second, char c) {
    switch (c) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return first / second;
        case '%':
            return first % second;
        case '^':
            int temp = first;
            for (int i = 1; i <= second; i++) {
                temp *= second;
            }
            return temp;
    }
}

int convert(string s) {
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isContain(s[i])) {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            int t = caculator(first, second, s[i]);
            
            st.push(t);
        } else {
            st.push(s[i] - '0'); /*convert char --> int*/
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
