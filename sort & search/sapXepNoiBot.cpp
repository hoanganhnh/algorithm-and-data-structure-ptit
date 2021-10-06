#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int ok = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                ok = 1;
                swap(a[j], a[j + 1]);
            }
        }
        if (ok) {
            cout << "Buoc " << i + 1 << ": ";
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bubble_sort(a, n);
}