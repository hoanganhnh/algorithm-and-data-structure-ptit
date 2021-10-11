#include<bits/stdc++.h>

using namespace std;

int n, k, a[1005];

void init() {
    cin >> n >> k;
    if (k > n) return;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
}

void output() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void pre() {
    int i = k;
    while(a[i] == a[i - 1] + 1) {
        i--;
    }
    if (i == 0) {
        for (int i = k; i >= 1; i--) {
            a[i] = n - k + i;
        }
    } else {
        a[i]--;

        for (int j = i + 1; j <= k; j++) {
            a[j] = n - k + j;
        }
    }

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        init();
        pre();
        output();
    }
}