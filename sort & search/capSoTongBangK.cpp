#include <bits/stdc++.h>

using namespace std;

int a[1005], n, k;

int resolve() {
    int s, cnt = 0;
    for (int i = 0; i < n; i++) {
        s = a[i];
        for (int j = i + 1; j < n; j++) {
            if (s + a[j] == k) cnt++;
        }
    }
    return cnt;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << resolve() << endl;;
    }

}