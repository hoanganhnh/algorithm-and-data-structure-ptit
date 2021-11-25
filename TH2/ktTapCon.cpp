#include <bits/stdc++.h>

using namespace std;

int n, a[105], ok, sum;

void Try(int i, int s) {
    if (s == sum / 2) {
        ok = 1;
        return;
    }

    if (ok) return;

    for (int j = i; j <= n; j++) {
        if (s + a[j] <= sum / 2) {
            Try(i + 1, s + a[j]);
        }
    }
}

void resolve() {
    cin >> n;
    ok = 0;
    sum = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    Try(1, 0);
    if (ok) cout << 1 << endl;
    else cout << 0 << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        resolve();
    }
}