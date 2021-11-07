#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void DFS(int k) {
    visited[k] = true;
    for (int x: adj[k]) {
        if (!visited[x]) {
            DFS(x);
        }
    }
}

void findPath(int s, int t) {
    memset(visited, false, sizeof(visited));
    DFS(s);
    if (!visited[t]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        init();
        int n;
        cin >> n;
        while (n--) {
            int x, y;
            cin >> x >> y;
            findPath(x, y);
        }
        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
    }
}