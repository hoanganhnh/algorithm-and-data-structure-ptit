#include <bits/stdc++.h>

using namespace std;

int n, a[100][100];
vector<string> res;
bool check = false;
bool ok[100][100];

void init() {
    res.clear();
    cin >> n;
    for (int i=1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            ok[i][j] = false;
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

    if (j < n && a[i][j + 1] && !ok[i][j + 1]) {
        ok[i][j] = true;
        Try(i, j + 1, s + "R");
        ok[i][j] = false;
    }

    if (i < n && a[i+1][j] && !ok[i+1][j]) {
        ok[i][j] = true;
        Try(i + 1, j, s + "D");
        ok[i][j] = false;
    }

    if (i != 1 && a[i - 1][j] && !ok[i - 1][j]) {
        ok[i][j] = true;
        Try(i - 1, j, s + "U");
        ok[i][j] = false;
    }

    if (j != 1 && a[i][j - 1] && !ok[i][j - 1]) {
        ok[i][j] = true;
        Try(i, j - 1, s + "L");
        ok[i][j] = false;
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