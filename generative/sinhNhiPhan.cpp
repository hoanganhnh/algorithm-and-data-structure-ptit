#include<iostream>

#define MAX 100

using namespace std;

int X[MAX], n;
bool ok = true;

void init() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        X[i] = 0;
    }
}

void output() {
    for(int i=1; i<=n; i++) {
        cout<<X[i];
    }
    cout<<" ";
}

void next() {
    int i = n;
    while(i > 0 && X[i]) { //duyệt từ vị trí bên phải nhất
        X[i] = 0;
        i--; //lùi lại vị trí sau
    }

    if (i > 0) {
        X[i] = 1;//gặp X[i] =0 đầu tiên ta chuyển thành 1
    } else {
        ok = false;
    }
}

int main(void) {
    init();
    while(ok) {
        output();
        next();
    }
    return 0;
}