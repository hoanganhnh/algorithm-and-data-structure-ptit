#include <bits/stdc++.h>

using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void init() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void DFS(int k) {
    visited[k] = true;
    for (int x: adj[k]) {
        if (!visited[x]) {
            parent[x] = k;
            DFS(x);
        }
    }
}

void findPath(int s, int t) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    DFS(s);
    if (!visited[t]) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        while (t != s) {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);

        reverse(path.begin(), path.end());

        for (int x: path) {
            cout << x << " ";
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        init();
        findPath(s, t);
        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
        cout << endl;
    }
}