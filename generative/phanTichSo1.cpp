#include<bits/stdc++.h>

using namespace std;

int n, a[100], ok, cnt;

void init() {
    cnt = 1;
    a[cnt] = n;
}

void next() {
    int i = cnt;

    while(i >= 1 && a[i] == 1) {
        i--;
    }

    if (i == 0) {
        ok = 0;
    } else {
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];

        if (q) {
            for (int j = 1; j <= q; j++) {
                cnt++;
                a[cnt] = a[i];
            }
        }

        if (r) {
            cnt++;
            a[cnt] = r;
        }
    }
}

void output() {
    cout << "(";
    for (int i = 1; i <= cnt; i++) {
        if (i != cnt) cout << a[i] << " ";
        else cout << a[i] << ") ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        ok = 1; 
        while(ok) {
            output();
            next();
        }
        cout << endl;
    }

}