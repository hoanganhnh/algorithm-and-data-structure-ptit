#include <bits/stdc++.h>

using namespace std;

int n;

int partition (int arr[], int l, int h){
    int x = arr[h]; // x chính là chốt
    int i = (l - 1); // i lấy vị trí nhỏ hơn l
    for (int j = l; j <= h- 1; j++) {
        if (arr[j] <= x){ 
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[h]); 
    return (i + 1); 
}
void quickSort(int arr[], int l, int h){
    if (l < h){
        int p = partition(arr, l, h); // tìm vị trí của chốt
        quickSort(arr, l, p - 1); //trị nửa bên trái
        quickSort(arr, p + 1, h); //trị nửa bên phải
    }
}


void in(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        quickSort(a, 0, n-1);
        in(a, n);
    }
    
}