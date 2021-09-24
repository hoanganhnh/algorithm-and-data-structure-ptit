#include<iostream>

using namespace std;
#define MAX 100

int X[MAX];

void init(int k) {
    for (int i = 1; i <= k; i++) {
        cin >> X[i];
    }
}

void output(int k) {
    for (int i = 1; i <= k; i++) {
        cout << X[i] << " " ;
    }
}

void next(int n , int k) {
    int i = k;
    while (i > 0 && X[i] == n - k + i) {
        i--;
    }

    if (i > 0) {
        X[i] = X[i] + 1;
        for (int j = i + 1; j <= k; j++) {
            X[j] = X[i] + j - i;
        }
        output(k);
    } else {
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
    }
}

int main(void) {
    int test;
    cin >> test;
    while(test--) {
        int n, k;
        cin >> n >> k;
        init(k);
        next(n, k);
        cout << "\n";
    }
    return 0;
}
