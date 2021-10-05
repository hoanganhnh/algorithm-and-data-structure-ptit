#include<bits/stdc++.h>

using namespace std;

int n, k, s, a[100], ok = 1;

void next() {
    int i = k;
    while (i >= 1 && a[i] == n - k + i) {
        i--;
    }

    if (i == 0) {
        ok = 0;
    } else {
        a[i]++;

        for (int j = i + 1; j <= k; j++) {
            a[j]  = a[j - 1] + 1;
        }
    }
}

bool check() {
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i];
    }

    return sum == s;
}

void output() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
        int cnt = 0;
        cin >> n >> k >> s;
        if (n < k) {
            cout << 0 << endl;
            continue;
        }
        if (n == 0 || k == 0 || s == 0) {
            break;
        }
        for (int i = 1; i <= k; i++) {
            a[i] = i;
        }
        while(ok) {
            if (check()) {
                cnt++;
            }
            next();
        }
        cout << cnt << endl;
        ok = 1;
    }
}

