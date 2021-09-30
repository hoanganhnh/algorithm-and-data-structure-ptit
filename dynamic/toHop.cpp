#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
int C[1005][1005];

void resolve() {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0 || i == j) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    resolve();
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << C[n][k] << endl;
    }
}