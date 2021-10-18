#include <bits/stdc++.h>

using namespace std;

void resolve() {
    int n;
    cin >> n;
    vector<int> a, res;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] != x) res.push_back(a[i]);
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

}

int main() {
    int t = 1;
    while (t--) {
        resolve();
    }
}