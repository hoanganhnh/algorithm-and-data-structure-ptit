#include <bits/stdc++.h>

using namespace std;

int n, m ,k, ok = 0;

void findCommon(long long ar1[], long long ar2[], long long ar3[], int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3) {
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
            cout << ar1[i] << " ";
            i++; j++; k++;
            ok = 1;
        } else if (ar1[i] < ar2[j]) {
            i++;
        } else if (ar2[j] < ar3[k]) {
            j++;
        } else {
            k++;
        }
    }
    if (!ok) cout << "NO";
    cout << endl;
}

void init() {
    cin >> n >> m >> k;
    long long x[n], y[m], z[k];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> z[i];
    }

    findCommon(x, y, z, n, m, k);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        init();
        ok = 0;
    }
}