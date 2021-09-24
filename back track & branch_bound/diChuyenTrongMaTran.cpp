#include <iostream>

using namespace std;
int n, m;
int value[100][100];
int r[100][100];
int count = 0;

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> value[i][j];
        }
    }
}

void Try(int i, int j) {
    if (i == n && j == m) {
        count++;
        return;
    }
    if (i < n) {
        Try(i + 1, j);
    }

    if (j < m) {
        Try(i , j + 1);
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        init();
        Try(1, 1);
        cout << count << endl;
        count = 0; 
    }
}