#include <bits/stdc++.h>

using namespace std;

void resolve() {
    int n, m, p, check = 0;
    cin >> n >> m >> p;
    long long a[n], b[m], c[p];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < p; i++) cin >> c[i];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m && k < p) {
        if (a[i] == b[j] && b[j] == c[k]) {
            cout << a[i] << " ";
            check = 1;
            i++; j++; k++;
        } else if (a[i] < b[j]) {
            i++;
        } else if (b[j] < c[k]) {
            j++;
        } else {
            k++;
        }
    }
    if (!check) cout << -1 ;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}