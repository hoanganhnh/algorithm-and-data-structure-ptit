#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> res;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int res = 0;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 1; i <= k; i++) {
            int t = a[n - i];
            cout << t << " ";
        }
        cout << endl;
    }
}