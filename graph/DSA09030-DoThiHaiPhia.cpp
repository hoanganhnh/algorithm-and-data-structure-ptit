#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int color[1005],n,m;
bool visited[1005], check;

void DFS(int u, int t){
	visited[u]=false;
    for (int v: adj[u]) {
        if (visited[v]) {
            if (color[v] == 0) {
                color[v] = 1 - color[u];
            }
            DFS(v,u);
        } else if (color[u]==color[v]) check = false;
    }
	
}

bool solve() {
	check = true;
	for (int i = 1; i<=n; i++){
		memset(visited, true, sizeof(visited));
		DFS(i,0);
		if (!check) return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		for (int i = 1; i<=1005; i++) adj[i].clear();
		memset(color, 0, sizeof(color));
		memset(visited, true,sizeof(visited));
		cin>>n>>m;
		for (int i = 0; i<m; i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		if (solve()) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
}