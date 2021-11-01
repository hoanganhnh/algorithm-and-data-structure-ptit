#include <bits/stdc++.h>

using namespace std;

vector<long long> res;
long long ans[101];

void init() {
    queue<string> q;
    q.push("9");
    res.push_back(9);

    while (true) {
        string top = q.front();
        q.pop();
        if (top.length() == 11) break;
        string chan = top + "0";
        string le = top + "9";
        res.push_back(stoll(chan));
        res.push_back(stoll(le));
        q.push(chan);
        q.push(le);
    }

    for (int i = 1; i <= 100; i++) {
        for (long long x : res) {
            if (x % i == 0) {
                ans[i] = x;
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        
        cout << ans[n] << endl;
    }

    return 0;
}