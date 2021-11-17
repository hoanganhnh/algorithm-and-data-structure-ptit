#include <bits/stdc++.h>

using namespace std;
vector<int> adj1[1001];
vector<int> adj2[1001];
int n, m;

void init() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj1[x].push_back(y);
        adj2[y].push_back(x);
    }
}

void check() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (adj1[i].size() == adj2[i].size()) {
            cnt++;
        }
    }
    if (cnt == n) {
        cout << 1;
    } else {
        cout << 0;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        check();
        for (int i = 0; i < 1002; i++) {
            adj1[i].clear();
            adj2[i].clear();
        }
    }
}