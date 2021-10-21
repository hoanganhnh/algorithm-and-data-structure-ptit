#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int res = 0;
        stack<int> idx;
        idx.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                idx.push(i);
            } else {
                idx.pop();
                if (!idx.empty()) {
                    res = max(res, i - idx.top());
                } else {
                    idx.push(i);
                }
            }
        }
        cout << res << endl;
    }
}
