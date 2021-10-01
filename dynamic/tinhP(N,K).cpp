#include<bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

long long dp[1005][1005];
/*
    nPk = n-1Pk + n-1Pk-1 * k
*/

void resolve() {
    for (int i = 0; i <= 1000; i++) dp[i][0] = 1;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] + j * dp[i - 1][j - 1]) % M;
        }
    }
}

int main() {
    int t;
    resolve();
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n < k) {
            cout << 0 << endl;
        } else {
            cout << dp[n][k] << endl;
        }

    }
}