#include <bits/stdc++.h>

using namespace std;

vector<int> values;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            values.push_back(temp);
        }

        sort(values.begin(), values.end());
        long long x = 0, y = 0;
        for (int i = 0; i < values.size(); i++) {
            if (i % 2 == 0) {
                x = x * 10 + values[i] ;
            } else {
                y = y * 10 + values[i] ;
            }
        }
        long long sum = x + y;
        cout << sum << endl;
        values.clear();
    }
}