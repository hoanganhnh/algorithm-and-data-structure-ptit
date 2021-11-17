#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
bool visited[1005];
bool cycle = false;
int a;

void init() {
    memset(visited,false,sizeof(visited));
    cin >> a;
    for (int i = 0; i < a - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void DFS(int u, int t){
	visited[u]=true;

    for (int x: adj[u]) {
        if (!visited[x]) {
            DFS(x, u);
        } else if (x != t) {
            cycle = true;
        }
    }
}

void solve(){
	for (int i = 1; i<=a; i++){
		memset(visited,false,sizeof(visited));
		DFS(i,0);
		if (cycle) {
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		init();
		solve();
		for (int i = 0; i < 1005; i++){
			adj[i].clear();
		}
        cycle = false;
	}
	return 0;
}