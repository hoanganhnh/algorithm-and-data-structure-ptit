#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
}

bool BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int x: adj[top]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                parent[x] = top;
            } else if (x != parent[top]) {
                return true;
            }
        }
    }
    return false;
}

void check() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (BFS(i)) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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