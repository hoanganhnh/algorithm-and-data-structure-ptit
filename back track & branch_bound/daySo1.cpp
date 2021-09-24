#include<iostream>

using namespace std;

void resolve() {
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 1; i <= n; i++) { // khởi tạo mảng đầu tiên
        cin >> arr[1][i];
    }

    int col = n - 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= col; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j + 1];
        }
        col--;
    }

    col = n;
    for (int i = 1; i <= n; i++) {
        cout<< '[';
        for (int j = 1; j < col; j++) {
            cout<< arr[i][j] << " ";
        }
        cout<< arr[i][col] << ']';
        col--;
        cout << "\n";
    }

}

int main() {
    int test;
    cin >> test;
    while(test --) {
        resolve();
    }
    return 0;
}