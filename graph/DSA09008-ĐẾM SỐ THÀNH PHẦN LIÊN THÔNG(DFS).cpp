#include<bits/stdc++.h>

using namespace std;

int n, m;
bool visited[1001];
vector<int> adj[1001];

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int k) {
    visited[k] = true;

    for (int x: adj[k]) {
        if (!visited[x]) {
            DFS(x);
        }
    }
}

void conectedCommonent() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            res++;
            DFS(i);
        }
    }
    cout << res;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        init();
        conectedCommonent();

        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
        cout << endl;
    }
}