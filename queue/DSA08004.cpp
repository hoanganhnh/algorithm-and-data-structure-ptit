#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        string s;
        cin >> k >> s;

        priority_queue<long long> p;
        int a[105] = {0};
        for (int i = 0; i < s.length(); i++) {
            a[s[i]]++;
        }

        for (int i = 65; i <= 90; i++) {
            if (a[i] != 0) p.push(a[i]);
        }

        while (k--) {
            int top = p.top();
            p.pop();
            top--;
            p.push(top);
        }

        long long res = 0;

        while (!p.empty()) {
            res += p.top() * p.top();
            p.pop();
        }

        cout << res << endl;
    }

    return 0;
}