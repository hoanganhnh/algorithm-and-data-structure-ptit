#include<bits/stdc++.h>

using namespace std;

int n,a,b;
char c;
bool du;
struct node{
    node* l;
    node* r;
    int data;
    node(int num){
        l=r=NULL;
        data=num;
    }
};

typedef node Node;

void themNode(Node* &t,int b,char c){
	if(c=='L') t->l=new Node(b);
	if(c=='R') t->r=new Node(b);
}

void createTree(Node* &t, int a,int b,char c){
	if(t==NULL) return;
	
	if(t->data == a) themNode(t,b,c);
	
	createTree(t->l,a,b,c);
	createTree(t->r,a,b,c);	
}

bool levelorder(Node* &t){

    //neu root rong thi tra ve true 
    if(t==NULL) return true;

    Node* temp;
    queue<Node*> q;
    q.push(t);

    //bien dem so node la 
    int count=0;
    while(!q.empty()){

        //neu con not la va queue khong rong nghia la tat ca cac la khong dung bac
        if(count > 0) return false;

        int len=q.size();
        for(int i=0;i<len;i++){
            temp=q.front();    q.pop();
            //kiem tra node la 
            if(temp->l == NULL && temp->r==NULL) count++;

            //dua node con vao hang doi 
            else{
                if(temp->l) q.push(temp->l);
                if(temp->r) q.push(temp->r);
            }
         }

    }
    return true;
}

void duyetTrungGian(Node* &t){
    if(t==NULL  || du==false){
        return;
    }

    if ((t->l == NULL && t->r !=NULL) || (t->l != NULL && t->r == NULL)){
        du=false;
    }
    duyetTrungGian(t->l);
    duyetTrungGian(t->r); 
}

void check(Node* &t){
    bool kiemtra1=levelorder(t);
    duyetTrungGian(t);

    if(kiemtra1 && du) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node* t=NULL;
        du=true;
        cin>>n;
		while(n--){
			cin>>a>>b>>c;
			
			if(t==NULL) {
				t=new Node(a);
				themNode(t,b,c);
			}else createTree(t,a,b,c);	
		}
		
        check(t);
    }
}