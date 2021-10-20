#include <bits/stdc++.h>

using namespace std;

/*
    string s
    @note: dp[i] = (i+1) * s[i] + dp[i - 1] * 10
*/

string s;

int convert(char c) {
    return c - '0';
}

void resolve(string num) {
    int n = num.length();

    long long dp[n];
    dp[0] = convert(num[0]);
    long long res = dp[0];

    for (int i = 1; i < n; i++) {
        int element = convert(num[i]);
        dp[i] = (i + 1) * element + 10 * dp[i - 1];

        res += dp[i];    
    }
    
    cout << (long long) res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;

        resolve(s);
    }

}