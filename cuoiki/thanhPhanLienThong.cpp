#include<bits/stdc++.h>
using namespace std;

vector<int> a[1005];
int visted[1005];
int n,m,u;

void dfs(int u){
	visted[u]=1;
	for(int v: a[u]){
		if(!visted[v]) dfs(v);
	}
}

void slove(){
	int kt=0;
	memset(a,0,sizeof(a));
	memset(visted,0,sizeof(visted));
	cin>>n>>m>>u;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(u);
	for(int i=1;i<=n;i++){
		if(!visted[i]) {
			cout<<i<<endl;
			kt=1;
		}
	}
	if(kt==0) cout<<"0";
	cout<<endl;
}

int main(){

	slove();
}
