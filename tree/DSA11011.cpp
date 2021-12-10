#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *l,*r;
	node(int x)
	{
		data=x;
		l=NULL;
		r=NULL;
	}
};

typedef node Node;

void noiNode(Node* &t, int b, char c){
	if (c=='L') t -> l = new Node(b);
	if (c=='R') t -> r = new Node(b);
}

void taoTree(Node* t, int a, int b, char c){
	if (t == NULL) return;
	if (t -> data == a) noiNode(t, b, c);
	taoTree(t-> l, a, b, c);
	taoTree(t-> r, a, b, c);
}

bool isFullTree(node *root)
{   
    if(root==NULL)
    return true;
    if(!root-> l && !root -> r)
    return true;
    if((root-> l) && (root -> r))
    {
    	return (isFullTree(root -> l) && isFullTree(root -> r));
    }
    return false;
}
		
void solve()
{
	int n; cin >> n;
	int a, b;
	char c;
	Node *t = NULL;
	while (n--){
		cin>>a>>b>>c;
		if (t == NULL){
			t = new Node(a);
			noiNode(t,b,c);
		} else {
			taoTree(t,a,b,c);
		}
	}
	if(isFullTree(t))
	cout<<1<<endl;
	else cout<<0<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}