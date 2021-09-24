#include<iostream>

#define MAX 100

using namespace std;

int X[MAX];
bool ok = true;

void init(int n) {
    for(int i=1; i<=n; i++) {
        X[i] = 0;
    }
}

void output(int n) {
    for(int i=1; i<=n; i++) {
        cout<<X[i];
    }
    cout<<" ";
}

bool checkBit (int n, int k) {
    int count = 0;
    for (int i = 1; i<=n; i++) {
        if (X[i] == 1) count++;
    }
    if (count == k) return true;
    return false;
}

void next(int n) {
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
    int test;
    cin >> test;
    while (test--) {
      int n, k;
      cin >> n >> k;
      init(n);
      while(ok) {
        if (checkBit (n, k)) {
          output(n);
          cout<< "\n";
        }
        next(n);
      }
      ok = true;
    }
    return 0;
}