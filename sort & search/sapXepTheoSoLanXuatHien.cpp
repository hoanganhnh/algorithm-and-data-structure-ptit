#include <bits/stdc++.h>

using namespace std;

int f[10005];

bool cmp(int first, int second) {
    if (f[first] == f[second]) return first < second;
    else return f[first] > f[second];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]]++;
        }

        sort(a, a + n, cmp);

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}