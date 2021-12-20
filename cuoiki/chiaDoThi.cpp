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
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {
    visited[u] = true;
    for (int x: adj[u]) {
        if (!visited[x]) {
            visited[x] = true;
            DFS(x);
        }
    }
}

int countComponentConnected() {
    int cnt =  0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

void resNextCountConnected() {
    int ok = 0;
    int currentConnected = countComponentConnected();
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int res = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                res++;
                DFS(j);
            }
        }
        if (currentConnected < res) {
            cout << i << " ";
            ok = 1;
        }
    }
    if (ok == 0) cout << 0;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        resNextCountConnected();
        for (int i = 1; i < 1002; i++) {
            adj[i].clear();
        }
    }
}