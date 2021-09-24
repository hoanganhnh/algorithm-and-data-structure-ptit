#include <bits/stdc++.h>

using namespace std;

int Index[100], value[100];
int n, k;
vector<vector <int>> res;

void init() {
    res.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    sort(value + 1, value + n +1);
}

void output() {
    if (res.size()) {
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << "[";
            for (int j = 0; j < res[i].size() - 1; j++) {
                cout << res[i][j] << " ";
            }
            cout << res[i][res[i].size() - 1] << "] ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        Index[i] = j;
        if (i == n) {
            int s = 0;
            for (int l = 1; l <= n; l++) {
                if (Index[l]) s += value[l];
            }

            if (s == k) {
                vector<int> x;
                for (int l = 1; l <= n; l++) {
                    if (Index[l]) x.push_back(value[l]);
                }
                res.push_back(x);
            }
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        init();
        Try(1);
        output();
    }
}