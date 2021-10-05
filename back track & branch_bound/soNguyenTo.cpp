#include <bits/stdc++.h>

using namespace std;
#define MAX 100

int n, p, sum;
int a[100];
vector<int> v, prime;
vector<vector<int>> res;

int isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

void init() {
    cin >> n >> p >> sum;
    for (int i = p + 1; i < sum; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
}

void output() {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void Try(int i, int s, int count) {
    if (s == sum && count == n) {
        res.push_back(v);
        return;
    }
    if (s > sum || count > n) return;

    for (int j = i; j < prime.size(); j++) {
        v.push_back(prime[j]);
        Try(j + 1, s + prime[j], count + 1);
        v.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        Try(0, 0, 0);
        cout << res.size() << endl;
        output();
        res.clear();
        v.clear();
        prime.clear();
    }
}

