#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        string str;
        cin >> str;
        int temp[300] = {0};
        int n = str.length();
        int res = 0;
        for (int i = 0; i < n; i++) {
            temp[str[i]]++;
            if (res < temp[str[i]]) {
                res = temp[str[i]];
            }
        }
        if ((res - 1) * (k - 1) > n - res) {
            cout << -1;
        } else {
            cout << 1;
        }
        cout << "\n";
    }
}