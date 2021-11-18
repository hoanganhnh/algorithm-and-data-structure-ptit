#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
// @Note: using BFS

void init() {
    cin >> n >> m;
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
            }
        }
    }
}

int countComponentConnected() {
    int cnt =  0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            BFS(i);
        }
    }
    return cnt;
}

void resNextCountConnected() {
    int currentConnected = countComponentConnected();
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int res = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                res++;
                BFS(j);
            }
        }
        if (currentConnected < res) {
            cout << i << " ";
        }
    }
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