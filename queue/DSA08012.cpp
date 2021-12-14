#include<bits/stdc++.h>
using namespace std;

int check(int a){
	vector<int> v(10,0);
	while (a){
		if (v[a%10]) return 0;
		v[a%10]=1;
		a/=10;
	} 
	return 1;
}

int count(int a, int b){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	int dem = 0;
	while (!q.empty()){
		int t = q.front();
		q.pop();
		if (t>=a && t<=b) dem++;
		for (int i = 0; i<=5; i++){
			if (t*10+i<=b && check(t*10+i)) q.push(t*10+i);
		}
	}
	return dem; 
}
int main (){
	int t;
	cin>>t;
	while (t--){
		int l,r;
		cin>>l>>r;
		cout<<count(l,r)<<endl;
	}	
}