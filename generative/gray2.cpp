#include<bits/stdc++.h>

using namespace std;

string s;

void init() {
    cin >> s;
}

void output() {
    string res = s;
    for (int i = 1; i < s.length(); i++) {\
        if ((s[i]) == (res[i-1])^0) res[i] = '0';
        else res[i] = '1';
    }
    cout << res << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        output();
    }
}