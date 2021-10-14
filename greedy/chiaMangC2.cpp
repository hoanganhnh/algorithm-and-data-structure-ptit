#include <bits/stdc++.h>

using namespace std;

void resolve() {
    int n , k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    int position = min(k, n -k);
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    int arrMin = a[position - 1];
    int arrMax = a[n - 1] - arrMin;

    cout << arrMax - arrMin << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        resolve();
    }
}