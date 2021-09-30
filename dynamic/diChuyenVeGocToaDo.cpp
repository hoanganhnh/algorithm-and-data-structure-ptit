#include <bits/stdc++.h>

using namespace std;

long long C[30][30];

void resolve() {
    for (int i = 0; i <= 25; i++) {
        C[i][0] = 1;
        C[0][i] = 1;
    }

    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= 25; j++) {
            C[i][j] = C[i - 1][j] + C[i][j - 1];
        }
    }
}

int main() {
    int t;
    cin >> t;
    resolve();
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << C[n][m] << endl;
    }
}