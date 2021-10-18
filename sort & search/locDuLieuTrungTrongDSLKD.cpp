#include <bits/stdc++.h>

using namespace std;

void resolve() {
    int n;
    cin >> n;
    int f[100005];
    vector<int> res;

    memset(f, 0, sizeof(f));

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        res.push_back(t);
        f[t]++;
    }
    for (int i = 0; i < n; i++) {
        if (f[res[i]]) {
            cout << res[i] << " ";
            f[res[i]] = 0;
        }
    }
    cout << endl;

}

int main() {
    int t = 1;
    while (t--) {
        resolve();
    }
}