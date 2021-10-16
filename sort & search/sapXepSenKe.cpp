#include <bits/stdc++.h>

using namespace std;

int a[1005], n;

void resolve() {
    int x = n - 1;
    int y = 0;
    while (true) {
        if (x == n/2 && n % 2 != 0) {
            cout << a[x] << " ";
            break;
        }
        cout << a[x] << " ";
        x -= 1;
        if (y == n/2 - 1 && n % 2 == 0) {
            cout << a[y] << " ";
            break;
        }
        cout << a[y] << " ";
        y += 1;
    }
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        resolve();
    }

}