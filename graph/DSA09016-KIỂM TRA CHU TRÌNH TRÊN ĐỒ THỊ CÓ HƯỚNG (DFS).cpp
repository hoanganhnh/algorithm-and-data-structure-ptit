#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];
int color[1001];
/**
 * int i = color[index]
 * i == 0 : not visited
 * i == 1 : visiting
 * i == 2 : visited
 */
// @Note: using DFS
void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(color, 0, sizeof(color));
}

bool DFS(int u) {
    color[u] = 1;
    for (int x: adj[u]) {
        if (color[x] == 0) {
            if (DFS(x)) return true;
        } else if (color[x] == 1) {
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void check() {
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (DFS(i)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        check();
        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
    }
}