#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* l;
	node* r;
	node(int x){
		data=x;
		l=NULL;
		r=NULL;
	}
};

typedef node Node;
void themNode(Node* &t,int x){
	if(t==NULL) t=new Node(x);

	else{
		if(x < t->data) themNode(t->l,x);
		if(x > t->data) themNode(t->r,x);
	}
}

void postOrder(Node* &t){
	if(t!=NULL){
		postOrder(t->l);
		postOrder(t->r);
		cout<<t->data<<" ";
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		Node* t=NULL;
		
		int n,x;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			themNode(t,x);
		}
		postOrder(t);
		cout<<endl;
	}
}