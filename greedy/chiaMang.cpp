#include <bits/stdc++.h>

using namespace std;

vector<int> values;
int n , k;
long long res;

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        values.push_back(temp);
    }

    sort(values.begin(), values.end());
    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < values.size(); i++) {
        if (i < k) {
            sum1 += values[i];
        } else {
            sum2 += values[i];
        }
    }

    res = abs(sum1 - sum2);
    sum1 = sum2 = 0;
    for (int i = 0; i < values.size(); i++) {
        if (i < n - k) {
            sum1 += values[i];
        } else {
            sum2 += values[i];
        }
    }

    res = max(res, abs(sum1 - sum2));
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        init();
        cout << res << endl;
        values.clear();
    }
}