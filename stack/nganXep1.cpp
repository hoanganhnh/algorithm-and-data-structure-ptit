#include<bits/stdc++.h>

using namespace std;

int st[205], n;

int main() {
    int idx = 0;
    string s;
    while (cin >> s) {
        if (s == "push") {
            cin >> n;
            st[++idx] = n;
        } else if (s == "pop") {
            if (idx) idx--;
        } else if (s == "show") {
            if (idx) {
                for (int i = 1; i <= idx; i++) {
                    cout << st[i] << " ";
                }
            } else {
                cout << "empty";
            }
            cout << endl;
        }
    }
}
