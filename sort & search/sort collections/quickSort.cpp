#include <bits/stdc++.h>

using namespace std;

int partition (int arr[], int l, int h) {
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

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);
        quickSort(a, l, p - 1);
        quickSort(a, p, h);
    }
}

void output(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    output(a, n);

}