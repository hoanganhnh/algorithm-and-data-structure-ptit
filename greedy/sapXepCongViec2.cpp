#include <bits/stdc++.h>

using namespace std;

int n, check[1005], kp[1005];

struct data {
    int j, d, p;
};

data a[1005];

bool cmp(data a, data b) {
    return a.p > b.p;
}

void resolve() {
    cin >> n;
    memset(check, 0, sizeof(check));

    for (int i = 0; i < n; i++) {
        cin >> a[i].j >> a[i].d >> a[i].p;
    }

    sort(a, a + n, cmp); // Sap xep theo loi nhuan giam gian

    for (int i = 0; i < n; i++) {
        for (int j = min(n, a[i].d) - 1; j >= 0; j--) {
            if (check[j] == 0) {
                kp[j] = i;
                check[j] = 1;
                break;
            }
        }
    }
    int res = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (check[i]) {
            cnt++;
            res += a[kp[i]].p;
        }
    }

    cout << "(" << cnt << ": " << res  << ")" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}