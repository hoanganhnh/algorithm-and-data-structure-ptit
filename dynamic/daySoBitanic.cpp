#include <bits/stdc++.h>

using namespace std;

int a[105], b[105], A[105], n;

void resolve() {
    int max_sum = INT_MIN;

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    a[1] = A[1];
    for (int i = 1; i <= n; i++) {
        a[i] = A[i];
        for (int j = 1; j <= i; j++) {
            if (A[j] < A[i] && a[i] < a[j] + A[i]) {
                a[i] = a[j] + A[i];
            }
        }
    }
    
    b[1] = A[1];
    for (int i = n; i >= 1; i--) {
        b[i] = A[i];
        for (int j = n; j >= i; j--) {
            if (A[j] < A[i] && b[i] < b[j] + A[i]) {
                b[i] = b[j] + A[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        max_sum = max(max_sum, (a[i] + b[i] - A[i]));
    }
    cout << max_sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        resolve();
    }

}