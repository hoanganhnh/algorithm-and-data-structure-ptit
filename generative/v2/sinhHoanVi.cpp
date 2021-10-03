#include<bits/stdc++.h>

using namespace std;

int n, a[100], isfinal = 1;
/*
    Sinh to hop nCk
    cấu hình đầu:  1, 2,..., k
    cấu hình cuối: n - k + 1, n - k + 2, ..., n
    duyệt k --> 1, xét xem tại mỗi vị trí đã đạt giá trị lớn nhất hay chưa

    Hàm có sẵn:
    next_premutation(a, a + n);
    prev_premutation(a, a + n);
*/

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void next() {
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) {
        i--;
    }

    if (i == 0) {
        isfinal = 0; // Cấu hình cuối cùng
    } else {
        int j = n;
        while(a[i] > a[j]) j--; // tìm a[i] nhỏ nhất trong đoạn [i + 1, n]
        swap(a[i], a[j]);
        /*
            reverse [i + 1, n]
            reverse(a + i + 1, a + n + 1);
        */
        int l = i + 1, r = n;
        while (l < r) {
            swap(a[l], a[r]);
            l++;
            r--;
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