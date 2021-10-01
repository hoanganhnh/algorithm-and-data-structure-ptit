#include<bits/stdc++.h>

using namespace std;

int c, n, W[105], C[105][25005];

int main() {
    cin >> c >> n;
    for (int i = 1; i <= n; i++) {
        cin >> W[i];
    }

    memset(C, 0, sizeof(C));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            C[i][j] =  C[i - 1][j];
            if (W[i] < j) {
                C[i][j] = max(C[i - 1][j], C[i - 1][j - W[i]] + W[i]);
            }
        }
    }

    cout << C[n][c] << endl;
    return 0;
}