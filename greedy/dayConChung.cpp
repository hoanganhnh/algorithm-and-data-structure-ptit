#include <bits/stdc++.h>

using namespace std;

vector<long long> x, y, z, value;
int n, m ,k;

void inputArr(vector<long long> &a, int n) {
    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        a.push_back(t);
    }
}

bool includeElement(vector<long long> &a, long long n) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == n) {
            return true;
        }
    }
    return false;
}

vector<long long> findMinTwoArr(vector<long long> &a, vector<long long> &b) {
    if (a.size() < b.size()) {
        return a;
    }
    return b;
}

vector<long long> findMinThreeArr(vector<long long> &a, vector<long long> &b, vector<long long> &c) {
    vector<long long> k = findMinTwoArr(a, b);
    return findMinTwoArr(k , c);
}

void init() {
    cin >> n >> m >> k;
    inputArr(x, n);
    inputArr(y, m);
    inputArr(z, k);

    vector<long long> minArr = findMinThreeArr(x, y, z);

    for (int i = 0; i < minArr.size(); i++) {
        int temp = minArr[i];
        if (includeElement(x, temp) && includeElement(y, temp) && includeElement(z, temp)) {
            if (!includeElement(value, temp))
                value.push_back(temp);
        }
    }

    for (int i = 0; i < value.size(); i++) {
        cout << value[i] << " ";
    }
    if (!value.size()) cout << "NO";
    cout << "\n";
    x.clear();
    y.clear();
    z.clear();
    value.clear();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        init();
    }
}