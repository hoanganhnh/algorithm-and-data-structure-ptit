#include <bits/stdc++.h>

using namespace std;
const long long M = 1e9 + 7;
long long n;
/**
 *@FIXME
*/
int resole(long long n) {
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i - 2]) % M;
        dp[i] %= M;
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << resole(n) << endl;
    }
}