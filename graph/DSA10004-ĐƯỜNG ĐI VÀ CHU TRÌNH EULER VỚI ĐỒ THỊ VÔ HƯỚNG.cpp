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

int check() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 == 1) {
            cnt++;
        }
    }
    if (cnt == 0) return 2;/* chu trình */
    if (cnt == 2) return 1;/* dường đi */
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        cout << check() << endl;

        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
    }
}