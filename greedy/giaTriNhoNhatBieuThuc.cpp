#include <bits/stdc++.h>

using namespace std;

int n;

void init() {
    cin >> n;

    vector<int> x;
    vector<int> y;
    for (int i = 0; i < n ; i++) {
        int t;
        cin >> t;
        x.push_back(t);
    }

    for (int i = 0; i < n ; i++) {
        int t;
        cin >> t;
        y.push_back(t);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += x[i] * y[n - i - 1];
    }

    cout << sum << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        init();
    }
}