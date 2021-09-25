#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        bool checkDuong = false;
        int max = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > 0) checkDuong = true;
            if (i == 0) {
                max = a[i];
            } else {
                if (max < a[i]) max = a[i]; // Xet truong hop toan so am
            }

        }

        int sum = 0, res = 0;

        if (checkDuong) {
            for (int i = 0; i < n; i++) {
                if (sum + a[i] < 0) {
                    sum = 0;
                    continue;
                }
                sum += a[i];
                if (res < sum) res = sum;
            }
            cout << res << endl;
        } else {
            cout << max << endl;
        }
    }
    return 0;
}