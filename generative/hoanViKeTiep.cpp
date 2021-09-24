#include<iostream>

#define MAX 100

using namespace std;

int X[MAX];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        cin>>X[i];
    }
}

void output(int n) {
    for (int i = 1; i <= n; i++) {
        cout << X[i]<< " ";
    }
    cout<< " ";
}

void next(int n) {
    int j = n - 1;
    while (j > 0 && X[j] > X[j + 1]) {
        j--;
    }

    if (j > 0) {
        int k = n;
        while (X[j] > X[k]) {
            k--;
        }
        int t=X[j]; X[j] = X[k]; X[k] = t;

        int r = j + 1, s = n;
        while (r <= s) {
            t=X[r]; X[r] = X[k]; X[k] = t;
            r++; s--;
        }
        output(n);
    } else {
        for (int i = 1; i <= n; i++) {
            cout << i<< " ";
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        init(n);
        next(n);
        cout<< "\n";
    }
    return 0;
} 