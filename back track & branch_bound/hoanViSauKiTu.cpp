#include <iostream>

#define MAX 100
using namespace std;
int index[MAX];
bool chuaxet[MAX];

void Init(int n){//thiết lập giá trị cho n
    for(int i = 0; i < n; i++) //thiết lập giá trị cho mảng chuaxet[]
    chuaxet[i]=true;
}

void Result(int n, int X[], string str){ //Đưa ra hoán vị hiện tại
    for(int i = 0; i < n; i++) 
        cout << str[X[i] - 1];
    cout << " ";
}

void Try(int i, int n, string X) { //thuật toán quay lui duyệt các hoán vị của 1, 2, .., n.
    for (int j = 0; j < n; j++){ //duyệt các khả năng j cho thành phần xi
        if(chuaxet[j]) { //nếu khả năng j đúng chưa được dùng đến
            index[i] = j + 1; //thiết lập thành phần xi là j
            chuaxet[j]=false; //thiết lập chuaxet[j] đã được dùng
            if(i==n - 1) {
                Result(n, index, X);
            } else {
                Try(i+1, n, X); //ta xác định tiếp thành phần thứ i+1
            }
            chuaxet[j]=true; //nhớ hoàn trả lại giá trị cho chuaxet[j]
        }
    }
}

int main(void){
    int test;
    cin >> test;
    while(test--) {
        string X;
        cin >> X;
        int n = X.length();
        Init(n); 
        Try(0, n, X);
        cout << "\n";
    }
}