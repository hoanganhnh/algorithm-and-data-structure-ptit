#include <bits/stdc++.h>

using namespace std;

int V, E, u, v;
bool visited[20], check;
vector<int> adj[20];

void init() {
    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
}

void Try(int u, int cnt) {
    if (cnt == V) {
        check = true;
        return;
    }
    for (int x: adj[u]) {
        if (!visited[x]) {
            visited[x] = true;
            Try(x, cnt + 1);
            visited[x] = false;
        }
    }
}

void handle() {
    for (int i = 1; i <= V; i++) {
        visited[i] = true;
        Try(i, 1);
        visited[i] = false;
    }
    cout << check << endl;
}

void reset() {
    check = false;
    for (int i = 0; i < 20; i++) {
        adj[i].clear();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        handle();
        reset();
    }
}