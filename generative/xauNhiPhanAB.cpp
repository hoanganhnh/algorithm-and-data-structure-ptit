#include<iostream>

using namespace std;

string s;
bool ok = true;

void init(int n) {
    for(int i=0; i < n; i++) {
        s[i] = 'A';
    }
}

void output(int n) {
    for(int i=0; i < n; i++) {
        cout << s[i];
    }
    cout<< " ";
}

void next(int n) {
    int i = n - 1;
    while(i >= 0 && s[i] == 'B') {
        s[i] = 'A';
        i--;
    }

    if (i >= 0) {
        s[i] = 'B';
    } else {
        ok = false;
    }
}

int main(void) {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        init(n);
        while(ok) {
            output(n);
            next(n);
        }
        ok = true;
        cout<<"\n";
    }
    return 0;
}