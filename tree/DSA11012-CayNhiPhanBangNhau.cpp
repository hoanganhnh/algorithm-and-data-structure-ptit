#include<bits/stdc++.h>

using namespace std;

bool du;
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

void themNode(Node* &t,int x,char c){
	if(c=='L') t->l=new Node(x);
	if(c=='R') t->r=new Node(x);
}

void taoTree(Node* &t,int a,int b,char c){
	if(t==NULL){
		return;
	}
	
	if(t->data==a) themNode(t,b,c);
	
	taoTree(t->l,a,b,c);
	taoTree(t->r,a,b,c);
}

void checkdu(Node* t,Node* t1){
	if(t==NULL || du ==false || t1==NULL) return;
	if(t->data != t1->data) du=false;
	
	checkdu(t->l,t1->l);
	checkdu(t->r,t1->r);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int n1;
		
		du=true;
		
		Node *t=NULL;
		Node *t1=NULL;
		while(n--){
			int a,d;
			char c;
			cin>>a>>d>>c;
			
			if(t==NULL){
				t=new Node(a);
				
				themNode(t,d,c); 
			}else taoTree(t,a,d,c);
		}
		
		cin>>n1;
		while(n1--){
			int a,d;
			char c;
			cin>>a>>d>>c;
			
			if(t1==NULL){
				t1=new Node(a);
				
				themNode(t1,d,c); 
			}else taoTree(t1,a,d,c);
		}
		
		if(n!=n1) du=false;
		else{
			checkdu(t,t1);
			if(du) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
}