#include <iostream>

using namespace std;

int a[20][20];
int n;

void init() {
    cin >> n;
    for (int j = 1; j <= n; j++) {
        cin >> a[n][j];
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        cout << "[";
        for (int j = 1; j < i; j++) {
            cout << a[i][j] << " ";
        }
        cout << a[i][i] << "] ";
    }
}

void Try(int i) {

    if (i == 0) {
        return;
    }
    for (int j = 1; j < i; j++) {
        a[i-1][j] = a[i][j] + a[i][j + 1];
    }
    Try(i - 1);
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        init();
        Try(n);
        output();
        cout << endl;
    }
}