#include<bits/stdc++.h>

using namespace std;
/*
 Sinh xâu nhị phân có đọ dài n
 1. Khỏi tạo xâu đầu tiên
 2. Duyệt từ n - 1 --> 0 nếu giá trị bằng 1 đổi thành 0

*/

int n, a[100], isfinal = 1;
string s;

void init() {
    cin >> s;
}

void output() {
    cout << s[0];
    for (int i = 1; i < s.length(); i++) {
        int res = s[i]^s[i-1];
        cout << res;
    }
    cout << " ";
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
    int t;
    cin >> t;
    while (t--) {
        init();
        output();
        
        cout << endl;
    }
}