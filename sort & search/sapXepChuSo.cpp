#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, temp ="";
        for (int i = 0; i < n; i++) {
            cin >> s;
            temp += s;
        }

        sort(temp.begin(), temp.end());

        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] != temp[i + 1])
                cout << temp[i] << " ";
        }
        cout << endl;
    }
}