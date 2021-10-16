#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a, a + n);

        int min = a[0], max = a[n - 1];
        int cnt = 0;

        for (int j = min; j <= max; j++) {
            cnt++;
        }
        
        cout << cnt - n << endl;
    }
}