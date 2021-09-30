#include <bits/stdc++.h>

using namespace std;
int n, F[1005], A[1005];

int resolve() {
    int res = 0;
    F[1] = 1;
    for (int i = 1; i <= n; i++) {
        F[i] = 1;
        for (int j = 1; j < i; j++) {
            if (A[j] <= A[i]) {
                F[i] = max(F[i], F[j] + 1);
            }
        }
        res = max(res, F[i]);
    }
    return n - res;
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