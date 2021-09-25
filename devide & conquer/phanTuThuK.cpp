#include <bits/stdc++.h>

using namespace std;

void initArray(vector<int> &a) {
    for (long long i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<int> a(m), b(n), c;
        initArray(a);
        initArray(b);
        for (int i = 0; i < a.size(); i++) {
            c.push_back(a[i]);
        }
        for (int i = 0; i < b.size(); i++) {
            c.push_back(b[i]);
        }
        sort(c.begin(), c.end());
        cout << c[k - 1] << endl;
    }
}