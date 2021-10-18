#include <bits/stdc++.h>

using namespace std;

int count(int x, int Y[], int n, int NoOfY[]) {
    if (x == 0) return 0;

    if (x == 1) return NoOfY[0];

    int* idx = upper_bound(Y, Y + n, x);
    int ans = (Y + n) - idx;


    ans += (NoOfY[0] + NoOfY[1]);

    if (x == 2) {
        ans -= (NoOfY[3] + NoOfY[4]);
    }

    if (x == 3) {
        ans += NoOfY[2];
    }

    return ans;
}

int countPairs(int X[], int Y[], int m, int n) {
    int NoOfY[5] = {0};

    for (int i = 0; i < n; i++) {
        if (Y[i] < 5) {
            NoOfY[Y[i]]++;
        }
    }

    sort(Y, Y + n);

    int res = 0;

    for (int i = 0; i < m; i++) {
        res += count(X[i], Y, n, NoOfY);
    }

    return res;
}

void resolve() {
    int x, y, cnt = 0;
    cin >> x >> y;
    int a[x], b[y];

    for (int i = 0; i < x; i++) {
        cin >> a[i]; 
    }

    for (int i = 0; i < y; i++) {
        cin >> b[i]; 
    }

    cout << countPairs(a, b, x, y) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}