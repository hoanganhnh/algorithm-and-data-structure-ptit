#include <bits/stdc++.h>

using namespace std;

void initArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

bool includeElement(int arr[], int n, int number) {
    bool check = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            check = true;
            break;
        }
    }
    return check;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n], b[n-1];
        initArray(a, n);
        initArray(b, n - 1);
        for (int i = 0; i < n; i++) {
            int temp=a[i];
            if (!includeElement(b, n-1, temp)) {
                cout << i + 1 << endl;
            }
        }
    }
}