#include <bits/stdc++.h>

using namespace std;

void init() {
    int n;
    cin >> n;
    vector<int> value(n);
    vector<int> x;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    sort(value.begin(), value.end());
    int a = value[0] * value[1];
    x.push_back(a);
    int b = value[n - 2] * value[n - 1];
    x.push_back(b);
    int c = value[n - 3] * value[n - 2] * value[n - 1];
    x.push_back(c);
    int d = value[0] * value[1] * value[n - 1];
    x.push_back(d);

    sort(x.begin(), x.end());

    cout << x[x.size() - 1] << endl;
}

int main() {
    init();
}