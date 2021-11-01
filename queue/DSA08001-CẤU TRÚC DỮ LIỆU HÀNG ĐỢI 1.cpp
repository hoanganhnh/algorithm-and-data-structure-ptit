#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<int> v;

        while (n--) {
            
            int num;
            cin >> num;

            if (num == 1) {
                cout << v.size() << endl;
            } else if (num == 2) {
                if (v.size()) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            } else if (num == 3) {
                int temp;
                cin >> temp;
                v.push(temp);
            } else if (num == 4) {
                if (v.size()) {
                    v.pop();
                }
                
            } else if (num == 5) {
                if (v.size()) {
                    cout << v.front() << endl;
                } else {
                    cout << -1 << endl;
                }
            } else if (num == 6) {
                if (v.size()) {
                    cout << v.back() << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }

    return 0;
}