#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> adj[1001];
vector<pair<int, int> > ans;
vector<pair<int, int> > currentGraph;
bool visited[1001];


void resetData() {
    for (int i = 0; i < 1002; i++) {
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        currentGraph.push_back({x, y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
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

/**
 *  @Note: count component connected 
 */
int currentConnected() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            res++;
            DFS(i);
        }
    }
    return res;
}

void resolve() {
    int cntCurrentConnect = currentConnected();
    for (int i = 0; i < m; i++) {
        resetData();
        for (int j = 0; j < m; j++) {
            if (j != i) {
                adj[currentGraph[j].first].push_back(currentGraph[j].second);
                adj[currentGraph[j].second].push_back(currentGraph[j].first);

            }
        }
        int nextConnected = currentConnected();
        
        if (cntCurrentConnect < nextConnected) {
            cout << currentGraph[i].first << " " << currentGraph[i].second << " ";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        resolve();
        resetData();
        currentGraph.clear();
        cout << endl;
    }
}