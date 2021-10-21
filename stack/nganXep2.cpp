#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    int idx = 0;
    int t;
    cin >> t;
    while (true) {
        t--;
        int n;
        string s;
        cin >> s;
        
        if (s == "PUSH") {
            cin >> n;
            v.push_back(n);
        } else if (s == "POP") {

            if (v.size()) v.pop_back();
        } else if (s == "PRINT") {
            if (v.size()) {
                cout << v[v.size() - 1] << endl;
            } else {
                cout << "NONE" << endl;
            }
        }
        if (!t) break;
    }
}
