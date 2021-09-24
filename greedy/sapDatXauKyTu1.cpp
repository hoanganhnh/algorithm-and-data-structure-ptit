#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
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
        if (res <= n/2 && n % 2 == 0) {
            cout << 1;
        } else if (res <= (n/2 +1) && n % 2 != 0) {
            cout << 1;
        } else {
            cout << -1;
        }
        cout << "\n";
    }
}