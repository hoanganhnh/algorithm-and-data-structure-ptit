#include <bits/stdc++.h>

using namespace std;

int n,x;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int res = 0;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == x) res++;
        }
        if (res) cout << res << endl;
        else cout << -1 << endl;
    }
}