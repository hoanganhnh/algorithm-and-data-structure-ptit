#include <bits/stdc++.h>

using namespace std;

void resolve() {
    int m, n;
    cin >> m >> n;
    int r[m + n], p[m], q[n];
    memset(r, 0, sizeof(r));

    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            r[i + j] += p[i] * q[j];
        }
    }

    for (int i = 0; i < m + n - 1; i++) {
        cout << r[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}