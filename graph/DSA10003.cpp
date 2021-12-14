#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1005];
bool visited[1005];
bool cycle = false;
int a,b;

void init() {
    cin>>a>>b;

    for (int i = 0; i<b; i++){
        int u, v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}
void DFS(int u, int t){
	visited[u]=true;
	for (int i = 0; i<ke[u].size(); i++){
		if (!visited[ke[u][i]])
			DFS(ke[u][i],u);
		else if (ke[u][i]!=t) cycle = true;
	}
}

void solve(){
	cycle = false;
	for (int i = 1; i<=a; i++){
		memset(visited,false,sizeof(visited));
		DFS(i,0);
		if (cycle) {
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		init();
		solve();
		for (int i = 0; i<1005; i++){
			ke[i].clear();
		}
	}
	return 0;
}