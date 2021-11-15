#include <bits/stdc++.h>

using namespace std;

void bubble_sort (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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
    bubble_sort(a, n);
    output(a, n);
}