#include<iostream>

using namespace std;
#define MAX 100

string s;

void next(int n) {
    int i = n;
    while(i > 0 && s[i] == '1') {
        s[i] = '0';
        i--;
    }

    if (i > 0) {
        s[i] = '1';
        cout << s;
    } else {
        for (int i = 0; i <= n; i++) {
            cout << '0';
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> s;
        int n = s.size() - 1;
        next(n);
        cout<< "\n";
    }
    return 0;
}