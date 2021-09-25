#include<bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long len = pow(2, n) / 2;
        while (1) {
            if (n == 1) {
                cout << 1;
                break;
            }
            if (len == k) {
                cout << n;
                break;
            }
            if (k > len) {
                k = len - (k - len);
            }
            n--;
            len /= 2;
        }
        cout << endl;
    }
}