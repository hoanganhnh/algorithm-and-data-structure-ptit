#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b, b + n);

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (a[j] == b[i]) {
                        swap(a[i], a[j]);
                        cnt++;
                        break;
                    }
                }
            }
        }

        cout << cnt << endl;
    }
}
