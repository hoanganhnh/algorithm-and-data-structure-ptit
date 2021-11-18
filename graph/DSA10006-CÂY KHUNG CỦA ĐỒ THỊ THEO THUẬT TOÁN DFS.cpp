#include <bits/stdc++.h>

using namespace std;

int n, m, u;
vector<int> adj[1001];
vector<pair<int, int> > trees;
bool visited[1001];

void init() {
    cin >> n >> m >> u;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {

    visited[u] = true;
    for (int x: adj[u]) {
        if (!visited[x]) {
            visited[x] = true;
            trees.push_back({u, x});
            DFS(x);
        }
    }
   
}

void resolve() {
    DFS(u);
    if (trees.size() != n - 1) {
        cout << -1 << endl;
    } else {
        for (auto tree: trees) {
            cout << tree.first << " " << tree.second << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        resolve();
        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
            trees.clear();
        }
    }
}
