#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];
int degree[1001];/* Bán bậc các đỉnh */

// @Note: using Kahn (BFS)

void init() {
    cin >> n >> m;
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
}

void Kahn() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cnt++;
        for (int x: adj[top]) {
            degree[x]--;
            if (!degree[x]) {
                q.push(x);
            }
        }
    }
    if (cnt == n) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        Kahn();
        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
    }
}