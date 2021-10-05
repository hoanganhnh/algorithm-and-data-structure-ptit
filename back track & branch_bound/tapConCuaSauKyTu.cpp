#include <bits/stdc++.h>

using namespace std;

int n;
bool a[100];
string s;
vector<vector<char>> res;

void add() {
    vector<char> temp;
    for (int i = 1; i <= n; i++)
        if (a[i])
            temp.push_back(s[i - 1]);
    res.push_back(temp);
}

void Try(int u) {
    if (u == n + 1) {
        add();
        return;
    }
    a[u] = 0;
    Try(u + 1);
    a[u] = 1;
    Try(u + 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        Try(1);
        sort(res.begin(), res.end());

        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j];
            }
            cout << " ";
        }
        cout << endl;
        res.clear();
    }
}