#include <bits/stdc++.h>

using namespace std;

int res = 0;

bool includeElement(int arr[], int n, int number) {
    bool check = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            res = i + 1;
            check = true;
            break;
        }
    }
    return check;
}
/*
    int index = lower_bound(array, array + arr.length, number) - array;
*/

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (includeElement(a, n, k)) {
            cout << res;
        } else {
            cout << "NO";
        }
        cout << endl;
        res = 0;
    }
}