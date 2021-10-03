#include<bits/stdc++.h>

using namespace std;

int n, k, a[100], isfinal = 1;

void init() {
    cin >> n >> k;
    if (k > n) return;
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

void output() {
    for (int i = 0; i < n; i++) {
        if (a[i]) cout << "B";
        else cout << "A";
    }
    cout << endl;
}

bool check() {
    int res = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count++;
        } else {
            count = 0;
        }

        if (count > k) return false;
        if (count == k) res++;
    }
    return res == 1;
}

void next() {
    int i = n - 1;
    while(i >= 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }

    if (i < 0) {
        isfinal = 0; // Cấu hình cuối cùng
    } else {
        a[i] = 1;
    }

}

int main() {
    int res = 0;
    init();
    while(isfinal) {
        if (check()) {
            res++;
        }
        next();
    }
    cout << res << endl;
    isfinal = 1;
    while(isfinal) {
        if (check()) {
            output();
        }
        next();
    }
}