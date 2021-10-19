#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c, l;

        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if (i % 2 == 0) {
                l.push_back(t);
            } else {
                c.push_back(t);
            }
        }

        sort(l.begin(), l.end()); // vị trí lẻ
        sort(c.begin(), c.end(), greater<int>()); // vị trí chẵn
        int i = 0, j = 0;
        while (true) {
            if (j < l.size()) {
                cout << l[j] << " ";
                j++;
            }
            if (i < c.size()) {
                cout << c[i] << " ";
                i++;
            }
            

            if (i == c.size() && j == l.size()) break;
        }

        cout << endl;
    }
}