#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bool visited[1001];
vector<int> adj[1001];

void init() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
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
        for (int x : adj[top]) {
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
        BFS(k);

        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
        cout << endl;
    }
}