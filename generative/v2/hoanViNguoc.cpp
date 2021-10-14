#include <iostream>

#define MAX 100

int X[MAX], dem=0, check;
bool OK = true;
using namespace std;

void init(int n){
    for (int i=1 ; i <= n; i++) {
        X[i] = n - i + 1;
    }
}

void Result(int n) {
    for(int i=1 ; i <= n; i++) {
        cout<<X[i];
    }
}

void Next_Permutation(int n) {
    int j = n - 1;
    while(j > 0 && X[j] < X[j + 1]) {
        j--;
    }

    if (j > 0) {
        int k = n;
        while(X[j] < X[k]) {
            k--;
        } 
        int t = X[j]; X[j] = X[k]; X[k]=t;
        int r = j + 1, s = n;
        while (r<=s) {
            t=X[r]; X[r]=X[s]; X[s]=t;
            r++; s--;
        }
    } else {
        OK = false;
        check = 0;
    }
}

int main(void) {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        init(n);
        check = 0;
        while(OK) {
            if (check)
                cout<<",";
            Result(n);
            check = 1;
            Next_Permutation(n);
        }
        OK = true;
        cout << "\n";
    }
}

