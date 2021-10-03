#include<bits/stdc++.h>

using namespace std;

int n, k, a[1005], isfinal = 1;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int tc;
        cin >> tc;
        string s;
        cin >> s;
        cout << tc << " ";
        if (next_permutation(s.begin(), s.end())) {
            cout << s << endl;
        } else {
            cout << "BIGGEST\n";
        }
    }
}