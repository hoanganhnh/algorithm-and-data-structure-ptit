#include <bits/stdc++.h>

using namespace std;

void init() {
    int n;
    cin >> n;
    vector<int> x, temp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        temp.push_back(a);
        x.push_back(a);
    }

    sort(temp.begin(), temp.end());
    bool check = true;
    for (int i = 0; i < n; i++) {
        if (x[i] != temp[i] && x[i] != temp[n - i - 1]) {
            check = false;
            break;
        }
    }

    if (check) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
    }
}