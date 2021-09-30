#include <bits/stdc++.h>

using namespace std;

int A[505][505], C[505][505];

int resolve(int n, int m) {
    memset(C, 0, sizeof(C));
    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i][j]) {
                C[i][j] = min(C[i - 1][j], min(C[i][j - 1], C[i - 1][j - 1])) + 1;
            }
            res = max(res, C[i][j]);
        }
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> A[i][j];
            }
        }
        cout << resolve(n, m) << endl;
    }
}