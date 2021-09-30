#include <bits/stdc++.h>

using namespace std;

int n, s, A[205], F[40005];

int resole() {
    memset(F, 0, sizeof(F));
    F[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= A[i]; j--) {
            if (F[j] == 0 && F[j - A[i]] == 1) {
                F[j] = 1;
            }
        }
    }
    return F[s];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        if (resole()) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
}