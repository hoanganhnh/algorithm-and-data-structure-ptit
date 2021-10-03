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
        cout << a[i] << " ";
    }
    cout << endl;
}

bool check() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            res++;
        }
    }
    return res == k;
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
    init();
    while(isfinal) {
        if (check()) {
            output();
        }
        next();
    }
}