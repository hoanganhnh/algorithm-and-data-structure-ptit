#include <bits/stdc++.h>

using namespace std;

vector<string> res;

void init() {
    queue<string> q;
    q.push("6");
    q.push("8");
    res.push_back("6");
    res.push_back("8");

    while (true) {
        string top = q.front();
        q.pop();
        if (top.length() == 15) break;
        string chan = top + "6";
        string le = top + "8";
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
        long long n;
        cin >> n;
        vector<string> v;
        for (string x : res) {
            if (x.length() <= n) {
                v.push_back(x);
            }
        }
        cout << v.size() << endl;
        for (string x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}