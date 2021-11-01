#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        queue<long long> v;
        v.push(1);
        while (true) {
            long long top = v.front();

            if (top % n == 0) {
                cout << top << endl;
                break;
            }
            v.pop();
            v.push(top * 10);
            v.push(top * 10 + 1);
        }
    }
}