#include <bits/stdc++.h>

using namespace std;

int v, e, n;
bool visited[1001];
vector<int> adj[1001];

void init() {
    cin >> v >> e >> n;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void BFS(int k) {
    queue<int> q;
    q.push(k);
    visited[k] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " ";

        for (int x: adj[top]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        BFS(n);

        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
        cout << endl;
    }
}