#include <bits/stdc++.h>

using namespace std;

long long F[10005];

void resolve() {
    F[0] = 0; F[1] = 1; F[2] = 2; F[3] = 3;
    for (int i = 4; i <= 10000; i++) {
        F[i] = i;
        for (int j = 1; j <= sqrt(i); j++) {
            F[i] = min(F[i], F[i - j*j] + 1);
        }
    }
}

int main() {
    int t;
    resolve();
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << F[n] << endl;
    }
}