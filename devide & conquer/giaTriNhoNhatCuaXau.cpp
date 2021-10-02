#include <bits/stdc++.h>

using namespace std;

int k;
string s;
int t[26];

void resole() {
    if (k > s.length()) return;
    memset(t, 0, sizeof(t));
    for (int i = 0; i < s.length(); i++) {
        t[s[i] - 'A']++;
    }

    priority_queue<int> pq;

    for (int i = 0; i < 26; i++) {
        if (t[i] != 0) {
            pq.push(t[i]);
        }
    }

    while(k > 0) {
        int temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
        k--;
    }

    long long res = 0;
    while(pq.size()) {
        long long t = pq.top();
        res += t * t;
        pq.pop();
    }

    cout << res << endl;
   
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> k >> s;
        resole();
    }
}