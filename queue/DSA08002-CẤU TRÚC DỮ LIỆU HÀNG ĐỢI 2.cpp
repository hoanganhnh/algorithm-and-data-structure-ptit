#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    queue<int> v;
    while (t--) {
        string s;
        cin >> s;

        if (s == "PUSH") {
            int n;
            cin >> n;
            v.push(n);
        } else if (s == "PRINTFRONT") {
            if (v.size()) {
                cout << v.front() << endl;
            } else {
                cout << "NONE" << endl;
            }
        } else if (s == "POP") {
            if (v.size()) {
                v.pop();
            }
        }
    }

    return 0;
}