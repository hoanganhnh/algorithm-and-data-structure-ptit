#include <bits/stdc++.h>

using namespace std;

int F[1005][1005];

int resole(string s) {
    int n = s.length();
    int res = 1;
    memset(F, 0, sizeof(F));
    for (int i = 0; i <= n; i++) {
        F[i][i] = 1; 
    }

    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            int j = i + k;
            if (k == 1 && s[i] == s[j]) {
                F[i][j] = 1;
            } else if (s[i] == s[j]) {
                F[i][j] = F[i + 1][j - 1];
            } else {
                F[i][j] = 0;
            }

            if (F[i][j]) {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << resole(s) << endl;
    }
}