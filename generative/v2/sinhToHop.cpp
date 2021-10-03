#include<bits/stdc++.h>

using namespace std;

int n, k, a[100], isfinal = 1;
/*
    Sinh to hop nCk
    cấu hình đầu:  1, 2,..., k
    cấu hình cuối: n - k + 1, n - k + 2, ..., n
    duyệt k --> 1, xét xem tại mỗi vị trí đã đạt giá trị lớn nhất hay chưa
*/

void init() {
    cin >> n >> k;
    if (k > n) return;
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void output() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void next() {
    int i = n - 1;
    while(i >= 1 && a[i] == n - k + i) {
        i--;
    }

    if (i == 0) {
        isfinal = 0; // Cấu hình cuối cùng
    } else {
        a[i]++;

        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        }
    }


}

int main() {
    init();
    while(isfinal) {
        output();
        next();
    }
}