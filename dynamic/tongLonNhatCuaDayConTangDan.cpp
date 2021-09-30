#include <bits/stdc++.h>

using namespace std;
int n, F[1005], A[1005];

int resolve() {
    int res = 0;
    memset(F, 0, sizeof(F));
    F[1] = A[1];
    for (int i = 1; i <= n; i++) {
        F[i] = A[i];
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                F[i] = max(F[i], F[j] + A[i]);
            }
        }
        res = max(res, F[i]);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        cout << resolve() << endl;
    }
}