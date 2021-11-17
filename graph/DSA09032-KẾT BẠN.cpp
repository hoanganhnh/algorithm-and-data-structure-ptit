#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];
bool visited[100001];

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

int BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    int cnt = 1;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int x: adj[top]) {
            if (!visited[x]) {
                cnt++;
                q.push(x);
                visited[x] = true;
            }
        }
    }
    return cnt;
}

int findMaxFriend() {
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int t = BFS(i);
            if (max < t) {
                max = t;
            }
        }
    }
    return max;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        cout << findMaxFriend() << endl;
        for (int i = 0; i <= 100001; i++) {
            adj[i].clear();
        }
    }
}