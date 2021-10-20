#include <bits/stdc++.h>

using namespace std;

int nthUgly(int n) {
    int dp[n];

    dp[0] = 1;

    int u2 = 0, u3 = 0, u5 = 0;
    int mul_2 = 2, mul_3 = 3, mul_5 = 5;

    for (int i = 1; i < n; i++) {
        dp[i] = min(mul_2, min(mul_3, mul_5));

        if (dp[i] == mul_2) {
            u2++;
            mul_2 = dp[u2] * 2;
        }

        if (dp[i] == mul_3) {
            u3++;
            mul_3 = dp[u3] * 3;
        }

        if (dp[i] == mul_5) {
            u5++;
            mul_5 = dp[u5] * 5;
        }

    }
    return dp[n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << nthUgly(n) << endl;
    }
}