#include <bits/stdc++.h>

using namespace std;

const long long m = (1e9 + 7);

long long power(long long a, long long b) {
    if (b == 1) {
        return a % m;
    } else {
        long long p = power(a, b / 2);

        if (b % 2 == 0) {
            return (p * p) % m;
        } else {
            return (((p * p) % m) * a) % m;
        }
    }
}

long long soDao(long long a) {
    long long m = a;
    long long res = 0;

    while (m > 0) {
        res = m % 10 + res * 10;
        m = m / 10;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long r = soDao(n);
        cout << power(n, r) << endl;
    }
    return 0;
}