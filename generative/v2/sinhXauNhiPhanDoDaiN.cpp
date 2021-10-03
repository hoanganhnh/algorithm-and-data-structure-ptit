#include<bits/stdc++.h>

using namespace std;
/*
 Sinh xâu nhị phân có đọ dài n
 1. Khỏi tạo xâu đầu tiên
 2. Duyệt từ n - 1 --> 0 nếu giá trị bằng 1 đổi thành 0

*/

int n, a[100], isfinal = 1;

void init() {
    cin >> n;
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
        output();
        next();
    }
}