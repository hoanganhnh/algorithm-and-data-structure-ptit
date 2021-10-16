#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
set<int> hop;
set<int> giao;

void findCommon(int ar1[], int ar2[], int n1, int n2) {
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (ar1[i] == ar2[j]) {
            cout << ar1[i] << " ";
            i++; j++;
        } else if (ar1[i] < ar2[j]) {
            i++;
        } else {
            j++;
        } 
    }
    cout << endl;
}

void resolve() {
    cin >> n >> m;
    int a[n], b[m];
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
        hop.insert(a[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
        v.push_back(b[i]);
        hop.insert(b[i]);
    }

    sort(v.begin(), v.end());

    for (int x: hop) {
        cout << x << " ";
    }
    cout << endl;

    findCommon(a, b, n, m);
    v.clear();
    hop.clear();
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }

}