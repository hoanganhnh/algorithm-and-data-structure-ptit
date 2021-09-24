#include <iostream>

#define MAX 100

int X[MAX], dem=0;
bool OK = true;
using namespace std;

void init(int n){
    for (int i=1 ; i <= n; i++) {
        X[i] = n - i + 1;
    }
}

void Result(int n){
    for(int i=1 ; i <= n; i++) {
        cout<<X[i];
    }
    cout<<" ";
}

void Next_Permutation(int n) { //sinh ra hoán vị kế tiếp
    int j = n - 1; //xuất phát từ vị trí j = n-1
    while(j > 0 && X[j] < X[j + 1]) {  //tìm chỉ số j sao cho X[j] > X[j+1]
        j--;
    }

    if (j > 0) { // nếu chưa phải hoán vị cuối cùng
        int k = n; //xuất phát từ vị trí k = n
        while(X[j] < X[k]) { //tìm chỉ số k sao cho X[j] > X[k]
            k--;
        } 
        int t = X[j]; X[j] = X[k]; X[k]=t; //đổi chỗ X[j] cho X[k]
        int r = j + 1, s = n;
        while (r<=s) { //lật ngược lại đoạn từ j+1,..,n
            t=X[r]; X[r]=X[s]; X[s]=t;
            r++; s--;
        }
    } else { //nếu là cấu hình cuối cùng
        OK = false; //ta kết thúc duyệt
    }
}
int main(void) { //đây là thuật toán sinh
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        init(n); //thiết lập cấu hình đầu tiên
        while(OK) { //lặp trong khi cấu hình chưa phải cuối cùng
            Result(n); //đưa ra cấu hình hiện tại
            Next_Permutation(n); //sinh ra cấu hình kế tiếp
        }
        OK = true;
        cout << "\n";
    }
}

