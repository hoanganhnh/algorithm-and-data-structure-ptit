#include <bits/stdc++.h>

using namespace std;

const long long m = (1e9 + 7);

long long power(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) {
        return a;
    } else {
        long long p = power(a, b / 2);
        p = p % m;

        if (b % 2 == 0) {
            return (p * p) % m;
        } else {
            return (((p * p) % m) * a) % m;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << power(n, k) << endl;
    }
    return 0;
}