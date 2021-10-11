#include <bits/stdc++.h>

using namespace std;
int n, k, a[21], check[21], sum = 0, dk = 0, ok = 0;

void init() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    dk = sum / k;
    sort(a, a + n);
}

void Try(int s, int cnt) {
    if (cnt == k) {
        ok = 1;
        return;
    }
    if (ok) return;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            check[i] = 1;   
            if (s == dk) Try(0, cnt + 1);
            else if (s < dk) Try(s + a[i], cnt + 1);
        }
        check[i] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        Try(0, 0);
        if (sum % k == 0) {
            cout << 1;
        } else {
            cout << 0;
        }
        cout << endl;
        ok = 0;
        sum = 0;
        dk = 0;
    }
}