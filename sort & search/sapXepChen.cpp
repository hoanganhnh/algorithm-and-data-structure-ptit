#include <bits/stdc++.h>

using namespace std;

void insert_sort(int arr[], int n) {
    int key, j;
    cout << "Buoc " << 0 << ": " << arr[0] << endl;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
        cout << "Buoc " << i << ": " ;
        for (int x = 0; x <= i; x++) {
            cout <<  arr[x] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    insert_sort(a, n);
}