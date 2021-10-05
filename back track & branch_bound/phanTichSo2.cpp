#include <bits/stdc++.h>

using namespace std;

int n, a[11];
vector<vector<int>> res;

void add(int n) {
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        temp.push_back(a[i]);
    }
    res.push_back(temp);
}

void Try(int i, int k, int curSum) {
    for (int j = k; j >= 1; j--) {
        if (curSum + j <= n) {
            a[i] = j;
            if (curSum + j == n) add(i);
            else Try(i + 1, j, curSum + j);
        }
    }
}

void output() {
    for (int i = 0; i < res.size(); i++) {
        cout << "(";
        for (int j = 0; j < res[i].size() - 1; j++) {
            cout << res[i][j] << " ";
        }
        cout << res[i][res[i].size() - 1] << ") ";
    }
    cout << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        res.clear();
        cin >> n;
        Try(1, n, 0);
        cout << res.size() << endl;
        output();
    }
}