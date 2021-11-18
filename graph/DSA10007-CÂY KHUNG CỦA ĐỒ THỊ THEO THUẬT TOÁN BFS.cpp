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

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int x: adj[top]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
                trees.push_back({top, x});
            }
        }
    }
}

void resolve() {
    BFS(u);
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
