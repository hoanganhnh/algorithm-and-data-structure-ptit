#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int h) {
    int x = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[h]);
    return i + 1;
}


void quickSort(int arr[], int l, int h) {
    if (l >= h) return;

    int p = partition(arr, l, h);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, h);
}

void output(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void resolve() {
    int n, m;
    cin >> n >> m;
    int s = n + m;
    int a[s];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n; i < s; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, s - 1);
    output(a, s);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}