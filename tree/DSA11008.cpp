#include <iostream>
using namespace std;

struct node{
    int data;
    node* l;
    node* r;
    node(int x){
        data = x;
        l = NULL;
        r = NULL;
    }
};
typedef node NODE;
void noiNode(NODE* &t, int b, char c){
    if (c == 'L') {
        t->l = new NODE(b);
    }
    if (c == 'R') {
        t->r = new NODE(b);
    }
}

void taoTree(NODE* t, int a, int b, char c){
    if (t == NULL) {
        return;
    }
    if (t->data == a) {
        noiNode(t, b, c);
    }
    taoTree(t->l, a, b, c);
    taoTree(t->r, a, b, c);
}

bool theoMuc(NODE* t, int level, int* leafLevel){
    if (t == NULL) {
        return true;
    }
    if (t->l == NULL && t->r == NULL) {
        if (*leafLevel == 0) {
            *leafLevel = level;
        }
        return (*leafLevel == level);
    }
    return theoMuc(t->l, level+1, leafLevel) && theoMuc(t->r, level+1, leafLevel);
}

void hoanHao(NODE* t){
    int level = 0;
    int leafLevel = 0;
    bool ok = theoMuc(t, level, &leafLevel);
    if (ok) {
        cout<<1;
    }
    else{
        cout<<0;
    }
    cout << endl;
}

int main(){
    int t = 0;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        NODE* t = NULL;
        while (n--) {
            int a,b;
            char c;
            cin>>a>>b>>c;
            if (t == NULL) {
                t = new NODE(a);
                noiNode(t, b, c);
            }
            else{
                taoTree(t, a, b, c);
            }
        }
        hoanHao(t);
    }
}