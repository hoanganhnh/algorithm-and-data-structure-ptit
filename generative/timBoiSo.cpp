#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> res;
const long long MAX = 1e17;

void resolve(long long i) {
    if (i > MAX) return;
    res.push_back(i);
    resolve(i*10);
    resolve(i*10 + 9);
}

int main() {
    int t;
    cin >> t;
    resolve(9);
    sort(res.begin(), res.end());
    while (t--) {
        cin >> n;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] % n == 0) {
                cout << res[i] << endl;
                break;
            }
        }
    }
}