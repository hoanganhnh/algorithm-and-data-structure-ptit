#include<bits/stdc++.h>

using namespace std;

void resolve() {
    int n;
    cin >> n;
    long long a[n + 1], dp[n + 1]={};

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    dp[1] = a[1]; dp[2] = a[2]; dp[3] = a[3] + a[1];

    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3]) + a[i];
    }

    sort(dp, dp + n + 1);

    cout << dp[n] << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}