#include <bits/stdc++.h>

using namespace std;
int n, x, a[105], b[105];
vector<vector<int>> res;

void init() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
}

void add(int n) {
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        if (b[i]) temp.push_back(b[i]);
    }
    sort(temp.begin(), temp.end());
    res.push_back(temp);
}

void output() {
    for (int i = 0; i < res.size(); i++) {
        cout << "{";
        for (int j = 0; j < res[i].size() - 1; j++) {
            cout << res[i][j] << " ";
        }
        cout << res[i][res[i].size() - 1] << "} ";
    }
}

void Try(int i, int k, int curSum) {
    for (int j = k; j >= 1; j--) {
        if (curSum + a[j] <= x) {
            b[i] = a[j];
            if (curSum + a[j] == x) add(i);
            else Try(i + 1, j, curSum + a[j]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        Try(1, n, 0);
        if (res.size()) {
            cout << res.size() << " ";
            sort(res.begin(), res.end());
            output();

        } else {
            cout << -1;
        }
        cout << endl;
        res.clear();
    }
}