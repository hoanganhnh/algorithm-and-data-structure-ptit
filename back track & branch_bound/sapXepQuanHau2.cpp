#include <bits/stdc++.h>

using namespace std;

int n;
bool cot[21], cheoXuoi[21], cheoNguoc[21];
int v[10][10];
int res = 0;

void init() {
    n = 8;
    for (int i = 1; i <= n; i++) {
        cot[i] = true;
    }

    for (int i = 1; i < 2*n; i++) {
        cheoXuoi[i] = true;
        cheoNguoc[i] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
}

void Try(int i, int sum) {
    for (int j = 1; j <= n; j++) {
        if (cot[j] && cheoXuoi[i-j+n] && cheoNguoc[i+j-1]) {
            sum += v[i][j];
            cot[j] = false;
            cheoXuoi[i-j+n] = false;
            cheoNguoc[i+j-1] = false;
            if (i == n) {
                res = max(sum, res);
            } else {
                Try(i + 1, sum);
            }
            sum -= v[i][j];
            cot[j] = true;
            cheoXuoi[i-j+n] = true;
            cheoNguoc[i+j-1] = true;
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test-- ) {
        init();
        Try(1, 0);
        cout << res << endl;
        res = 0;
    }
}