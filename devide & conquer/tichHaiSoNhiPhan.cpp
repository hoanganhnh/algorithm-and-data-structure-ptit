#include <bits/stdc++.h>

using namespace std;

long long resolve(string s) {
    long long res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 2 + s[i] - '0';
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << resolve(a) * resolve(b)<< endl;
    }
}