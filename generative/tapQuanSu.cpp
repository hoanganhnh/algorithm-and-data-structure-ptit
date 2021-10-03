#include<bits/stdc++.h>

using namespace std;

int n, k, a[100];

set<int> se;

void init() {
    cin >> n >> k;
    for (int i= 1; i <= k; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
}

void output() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void next() {
    int i = k;
    while(i >= 1 && a[i] == n - k + i) {
        i--;
    }

    if (i == 0) {
        cout << k << endl;
    } else {
        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j]  = a[j - 1] + 1;
        }

        int count = 0;
        for (int i = 1; i <= k; i++) {
            if (se.count(a[i]) != 0) {
                count++;
            }
        }
        cout << k - count << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        next();
        se.clear();
    }
}