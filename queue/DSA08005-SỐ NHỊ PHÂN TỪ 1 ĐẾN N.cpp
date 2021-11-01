#include <bits/stdc++.h>

using namespace std;

vector<string> res;

void init() {
    queue<string> q;
    q.push("1");
    res.push_back("1");
    int cnt = 0;

    while (res.size() < 10000) {
        cnt++;
        string top = q.front();
        q.pop();
        string chan = top + "0";
        string le = top + "1";
        res.push_back(chan);
        res.push_back(le);
        q.push(chan);
        q.push(le);
    }
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}