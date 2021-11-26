#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e9;
typedef pair<int, int> II;
int n, m, start;
int D[1005], parent[1005];
vector<II> List[1005];
priority_queue<II, vector<II>, greater<II>> Q;

void Dijkstra(int st) {
    int u, v;
    for (int i = 1; i <= n; i++) {
        D[i] = MAX;
        parent[i] = -1;
    }
    D[st] = 0;

    while (!Q.empty()) {
        Q.pop();
    }
    Q.push({0, st});

    while (!Q.empty()) {
        u = Q.top().second;
        Q.pop();

        for (int i = 0; i < List[u].size(); i++) {
            v = List[u][i].second;
            int d_u_v = List[u][i].first;
            if (D[u] + d_u_v < D[v]) {
                D[v] = D[u] + d_u_v;
                parent[v] = u;
                Q.push({D[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << D[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int u, v, k;
        cin >> n >> m >> start;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> k;
            List[u].push_back({k, v});
            List[v].push_back({k, u});
        }
        Dijkstra(start);
        for (int i = 0; i <= n; i++) {
            List[i].clear();
        }
    }
    
}