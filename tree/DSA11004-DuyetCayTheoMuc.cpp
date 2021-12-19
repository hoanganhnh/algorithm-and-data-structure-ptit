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

typedef node NODE;
void noiNode(NODE* &t,int b,char c){
	if(c=='L') t->l=new NODE(b);
	if(c=='R') t->r=new NODE(b);
}

void taoTree(NODE* t,int a,int b,char c){
	if(t==NULL) return;
	if(t->data==a) noiNode(t,b,c);
	
	taoTree(t->l,a,b,c);
	taoTree(t->r,a,b,c);
}

void theoMuc(NODE *node){
	if(node==NULL) return;
	
	queue<NODE*> q;
	q.push(node);
	while(!q.empty()){
		NODE *node=q.front();
		q.pop();
		cout<<node->data<<" ";
		if(node->l !=NULL) q.push(node->l);
		
		if(node->r !=NULL) q.push(node->r);
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a,d;
		char c;
		NODE *t= NULL;
		cin>>n;
		while(n--){
			cin>>a>>d>>c;
				
			if(t==NULL) {
				t=new NODE(a);
				noiNode(t,d,c);
			}else{
				taoTree(t,a,d,c);
			}
			
		}	
		theoMuc(t);
	}
}