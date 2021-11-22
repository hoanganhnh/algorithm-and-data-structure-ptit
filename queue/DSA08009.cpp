#include <bits/stdc++.h>

using namespace std;

int resolve(int s, int e) {
    queue<pair<int, int> > q;
    set<int> se;
    se.insert(s);
    q.push({s, 0});

    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == e) {
            return top.second;
        }
        if (top.first * 2 == e || top.first - 1 == e) {
            return top.second + 1;
        }
        if (se.find(top.first * 2) == se.end() && top.first < e) {
            q.push({top.first * 2, top.second + 1});
            se.insert(top.first * 2);
        }
        if (se.find(top.first - 1) == se.end() && top.first > 1) {
            q.push({top.first - 1, top.second + 1});
            se.insert(top.first - 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, e;
        cin >> s >> e;
        cout << resolve(s, e) << endl;
    }
}