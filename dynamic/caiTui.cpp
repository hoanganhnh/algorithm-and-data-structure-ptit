#include <bits/stdc++.h>

using namespace std;

int F[1005][1005], N, V, A[1005], C[1005];

int resolve() {
    int i, j;
    for (i = 0; i <= N; i++) {
        F[i][0] = 0;
    }
    for (i = 0; i <= V; i++) {
        F[0][i] = 0;
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= V; j++) {
            F[i][j] = F[i - 1][j];
            if (j >= A[i]) {
                F[i][j] = max(F[i - 1][j - A[i]] + C[i], F[i - 1][j]);
            }
        }
    }
    return F[N][V];
}


int main() {
    int t, i;
    cin >> t;
    while (t--) {
        cin >> N >> V;
        for (i = 1; i <= N; i++) {
            cin >> A[i];
        }

        for (i = 1; i <= N; i++) {
            cin >> C[i];
        }

        cout << resolve() << endl;
    }

}