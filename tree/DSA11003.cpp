#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE 1001

int SearchValue(int a[], int x, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
    return -1;
}

void PostOrder(int InOrder[], int PreOrder[], int n) {
    int root = SearchValue(InOrder, PreOrder[0], n);
    if (root != 0) {
        PostOrder(InOrder, PreOrder + 1, root);
    }
    if (root != n - 1) {
        PostOrder(InOrder + root + 1, PreOrder + root + 1, n - root - 1);
    }
    cout << PreOrder[0] << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int InOrder[MAX_NODE], PreOrder[MAX_NODE];
        for (int i = 0; i < n; i++) {
            cin >> InOrder[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> PreOrder[i];
        }
        PostOrder(InOrder, PreOrder, n);
        cout << endl;
    }
}