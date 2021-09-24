#include <iostream>

#define MAX 100

using namespace std;

int X[MAX], n, k;
bool OK = true;

void init(int k) { 
    for (int i = 1; i <= k; i++) {
        X[i] = i;
    }
}

void output(int k) {
    for (int i = 1; i <= k; i++) {
        cout << X[i];
    }
    cout<< " ";
}
void Next_Combination(int n, int k) { //sinh tập con k phần tử từ tập con bất kỳ
    int i = k; //duyệt từ vị trí bên phải nhất của tập con
    while (i > 0 && X[i] == n - k + i) {//tìm i sao cho xi  n-k+i
        i--;
    } 
    if (i > 0) { //nếu chưa phải là tập con cuối cùng
        X[i] = X[i] + 1; //thay đổi giá trị tại vị trí i: xi = xi +1;
        for (int j = i + 1; j <= k; j++) {//các vị trí j từ i+1,.., k
            X[j] = X[i] + j - i; // được thay đổi là xj = xi +j - i;
        } 
    } else {//nếu là tập con cuối cùng
        OK = false; //ta kết thúc duyệt
    } 
}

int main(void) {
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        init(k); //khởi tạo cấu hình đầu tiên
        while (OK) { //lặp trong khi cấu hình chưa phải cuối cùng
            output(k); //đưa ra cấu hình hiện tại
            Next_Combination(n, k); //sinh ra cấu hình kế tiếp
        }
        OK = true;
        cout<<"\n";
    }
}