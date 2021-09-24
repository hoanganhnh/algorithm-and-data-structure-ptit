#include <iostream>

using namespace std;

string s;
bool ok = true;

void init(int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            s[i] = 'H';
        } else {
            s[i] = 'A';
        }
    }
}

void output(int n) {
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
}

void next(int n) {
    int j = n - 2;

    while(j > 1 && s[j] == 'H') {
        s[j] = 'A';
        j--;
    }

    if (j > 1) {
        if (s[j - 1] == 'A') {
            s[j] = 'H'; 
        } else {
            next(j + 1);
        }
    } else {
        ok = false;
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        init(n);
        while (ok) {
            output(n);
            next(n);
            cout << "\n";
        }
        ok = true;
    }
    return 0;
}