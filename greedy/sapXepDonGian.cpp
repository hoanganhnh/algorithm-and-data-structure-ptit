#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];

int resolve() {
    int L[n];
    L[0] = 1

    for (int i = 1; i < n; i++) {
        L[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;
            }
        }
    }
    
    return *max_element(L, L + n);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << n - resolve() << endl;
}