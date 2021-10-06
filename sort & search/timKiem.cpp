#include <bits/stdc++.h>

using namespace std;

bool bs(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l + r) / 2;

        if (arr[m] == x) {
            return true;
        } else if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int a[x];
        for (int i = 0; i < x; i++) {
            cin >> a[i];
        }
        if (bs(a, x, y)) {
            cout << 1;
        } else {
            cout << -1;
        }
        cout << endl;
    }
}