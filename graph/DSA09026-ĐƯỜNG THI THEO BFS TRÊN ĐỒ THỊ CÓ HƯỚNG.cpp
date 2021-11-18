#include <bits/stdc++.h>

using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void init() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void BFS(int k) {
    queue<int> q;
    q.push(k);
    visited[k] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int x: adj[top]) {
            if (!visited[x]) {
                parent[x] = top;
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void findPath(int s, int t) {/* c1 */
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    BFS(s);

    if (!visited[t]) {
        cout << - 1 << endl;
    } else {
        vector<int> path;
        while (t != s) {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());

        for (int x: path) {
            cout << x << " ";
        }
    }
}

void findPathGarph(int s, int e) { /* c2 */
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    BFS(s);

    if (!visited[e]) {
        cout << - 1 << endl;
    } else {
        stack<int> st;
        st.push(e);
        while (st.top() != s) {
            int top = st.top();
            st.push(parent[top]);
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            cout << top << " ";
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        init();
        findPathGarph(s, t);
        for (int i = 0; i < 1002; i++) {
            adj[i].clear();
        }
        cout << endl;
    }
}