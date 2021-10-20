#include <bits/stdc++.h>

using namespace std;
/*
    @FIXME
*/

long long resolve(int n) {
    long long a[n];
    a[0] = 1; a[1] = 1;

    for (int i = 2; i <= n; i++) {
        a[i] = 0;
        for (int j = 0; j < i; j++) {
            a[i] += a[j] * a[i - j - 1];
        }
    }

    return a[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << resolve(n) << endl;
    }
}