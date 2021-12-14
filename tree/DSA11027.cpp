#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *l;
    node *r;
    node(int x){
    	data=x;
    	l=NULL;
    	r=NULL;
	}
};
typedef node Node;


Node* createBST(int *a, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end)/2;
    Node* temp = new Node(a[mid]);
    temp->l = createBST(a, start, mid - 1);
    temp->r = createBST(a, mid + 1, end);
    return temp;
}


int getLeafCount(Node* t){
	if (t==NULL) return 0;
	if (t->l==NULL && t->r==NULL) return 1;
	else return getLeafCount(t->l)+getLeafCount(t->r);
}

main(){
    int t,n,i;
    cin>>t;
    while(t--){
        cin >> n;
        int a[n];
        for(i = 0; i < n; ++i) cin >> a[i];
        sort(a, a+n);
        Node *temp = createBST(a, 0, n - 1);
        cout<<getLeafCount(temp);
        cout << endl;
    }
}