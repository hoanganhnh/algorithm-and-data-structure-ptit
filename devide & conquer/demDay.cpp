#include <bits/stdc++.h>

using namespace std;

const long long M = 123456789;
long long n;

long long resolve(long long x, long long k) {
    if (k == 0) return 1;

    long long temp = resolve(x, k/2);
    if (k % 2 == 0) {
        return temp * temp % M;
    }
    else {
        return temp * temp % M * x % M;
    }

    return x%M;
}

void init() {
    cin >> n;
    if (n == 1) cout << 1 << endl;
    else cout << resolve(2, n - 1) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
    }
}