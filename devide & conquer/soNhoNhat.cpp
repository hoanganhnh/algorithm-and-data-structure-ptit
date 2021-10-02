#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        stack<int> stk;

        while(s > 0) {
            d--;
            if (s > 9) {
                stk.push(9);
                s -= 9;
            } else {
                stk.push(s);
                break;
            }
        }

        if (d < 0) {
            cout << -1 << endl;
        } else {
            if (d > 0) {
                int so = stk.top();
                stk.pop();
                stk.push(so - 1);
                while (d > 1) {
                    stk.push(0);
                    d--;
                }
                stk.push(1);
            }

            while(stk.size() > 0) {
                cout << stk.top();
                stk.pop();
            }
            cout << "\n";
        }
    }
}