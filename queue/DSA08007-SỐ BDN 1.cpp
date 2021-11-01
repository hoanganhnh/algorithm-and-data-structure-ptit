#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        int cnt = 0;
        cin >> n;
        queue<long long> v;
        v.push(1);
        while (v.front() <= n) {
            long long top = v.front();
            v.pop();
            v.push(top * 10);
            v.push(top * 10 + 1);
            cnt++;
        }
        cout << cnt << endl;
    }
}