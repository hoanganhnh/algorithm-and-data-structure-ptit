#include <bits/stdc++.h>

using namespace std;

/**
 * Hàng đợi hai đầu @fn: dequeue
 * 
 * method():
 * size()
 * push_back()
 * push_front()
 * pop_back()
 * pop_front()
 * back()
 * front()
 * empty()
 */

int main() {
    int t;
    cin >> t;
    deque<int> v;
    while (t--) {
        string s;
        cin >> s;

        if (s == "PUSHFRONT") {
            int n;
            cin >> n;
            v.push_front(n);
        } else if (s == "PRINTFRONT") {
            if (v.size()) {
                cout << v.front() << endl;
            } else {
                cout << "NONE" << endl;
            }
        } else if (s == "POPFRONT") {
            if (v.size()) {
                v.pop_front();
            }
        } else if (s == "PUSHBACK") {
            int n;
            cin >> n;
            v.push_back(n);
        } else if (s == "PRINTBACK") {
            if (v.size()) {
                cout << v.back() << endl;
            } else {
                cout << "NONE" << endl;
            }
        } else if (s == "POPBACK") {
            if (v.size()) {
                v.pop_back();
            }
        }
    }

    return 0;
}