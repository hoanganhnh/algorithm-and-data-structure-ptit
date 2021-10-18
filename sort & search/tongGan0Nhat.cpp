#include <bits/stdc++.h>

using namespace std;

void resolve() {
    int n;
    cin >> n;
    int f[n];
    long long res = 1e9 + 7;

    for (int i = 0; i < n; i++) {
       cin >> f[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(f[i] + f[j]) < abs(res)) {
                res = f[i] + f[j];
            }
        }
    }

    cout << res << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}