#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> adj[1001];


        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }

        for (int i = 1; i <= n; i++) {
            cout << i << ": ";
            for (int x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
}