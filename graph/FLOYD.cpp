#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e9;

int C[105][105], n, m;

void Floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (C[i][j] > C[i][k] + C[k][j]) {
                    C[i][j] =  C[i][k] + C[k][j];
                }
            }
        }
    }
}

main() {
    int u, v, k, q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                C[i][j] = 0;
            }
            else {
                C[i][j] = MAX;
            }
        } 
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> k;
        C[u][v] = C[v][u] = k;
    }
    Floyd();
    int x;
    cin >> x;
    while (x--) {
        int u, v;
        cin >> u >> v;
        cout << C[u][v] << endl;
    }
}