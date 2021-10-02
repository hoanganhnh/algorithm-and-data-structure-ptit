#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

long long n;

void resolve() {

    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long> >pq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long res = 0;
    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = (a + b) % M;
        pq.push(sum);
        res += sum;
        res %= M;

    }
    cout << res << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}