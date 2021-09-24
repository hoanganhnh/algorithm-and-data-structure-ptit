#include <iostream>

using namespace std;

#define MAX 100

char X[MAX];
bool ok = true;

void init(int k) {
    for (int i = 65; i <= k + 64; i++) {
        X[i] = char(i);
    }
}

void output(int k) {
    for (int i = 65; i <= k + 64; i++) {
        cout << X[i];
    }
    cout << "\n";
}

void next(int n, int k) {
    int j = k + 64;
    while(j > 64 && X[j] == n - k + j) {
        j--;
    }

    if (j > 64) {
        X[j] = X[j] + 1;
        for (int i = j+1; i <= k + 64; i++) {
            X[i] = X[j] + i - j;
        }
    } else {
        ok = false;
    }
}


int main() {
    int test;
    cin >> test;
    while (test--) {
        int n , k;
        cin >> n >> k; 
        init(k);
        while (ok) {
            output(k);
            next(n, k);
        }
        ok = true;
    }
}