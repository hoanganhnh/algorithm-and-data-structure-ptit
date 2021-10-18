#include <bits/stdc++.h>

using namespace std;

int prime[1000005];

const long long MAX = 1000000;

void sieve() {
    for (int i = 0; i <= MAX; i++) {
        prime[i] = 1;
    }

    prime[0] = 0; prime[1] = 0;

    for (int i = 2; i <= 1000; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= MAX; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    sieve();
    while (t--) {
        int n, ok = 0;
        cin >> n;

        for (int i = 2; i <= n; i++) {
            if (prime[i] && prime[n - i]) {
                cout << i << " " << n - i << endl;
                ok = 1;
                break;
            }
        }

        if (!ok) cout << -1 << endl;
    }
}