#include <bits/stdc++.h>

using namespace std;

int n, a[100][100];
vector<string> res;
bool check = false;

void init() {
    res.clear();
    cin >> n;
    for (int i=1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    check = false;
}

void output() {
    if (check) {
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size();i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

void Try(int i, int j, string s) {
    if (i == 1 && j == 1 && !a[i][j]) {
        check = false;
        return;
    }

    if (i == n && j == n && a[n][n]) {
        res.push_back(s);
        check = true;
        return;
    }

    if (j < n && a[i][j + 1]) {
        Try(i, j + 1, s + "R");
    }

    if (i < n && a[i+1][j]) {
        Try(i + 1, j, s + "D");
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        init();
        Try(1, 1, "");
        output();
    }
}