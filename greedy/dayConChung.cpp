#include <bits/stdc++.h>

using namespace std;
/**
 *@FIXME
*/
vector<long long> x, y, z;
int n, m ,k;

void inputArr(vector<long long> &a, int n) {
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
}

vector<long long> findSubsequence(vector<long long> &a, vector<long long> &b) {
    vector<long long> temp;
    long long A[a.size()];
    long long B[b.size()];
    memset(A, 1, sizeof A);
    memset(B, 1, sizeof B);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j] && A[i] && B[j]) {
                temp.push_back(b[j]);
                A[i] = B[j] = 0;
            }
        }
    }
    return temp;
}

void init() {
    cin >> n >> m >> k;
    inputArr(x, n);
    inputArr(y, m);
    inputArr(z, k);

    vector<long long> h = findSubsequence(x, y);
    vector<long long> minArr = findSubsequence(h, z);
    if (minArr.size()) {

        for (int i = 0; i < minArr.size(); i++) {
            cout << minArr[i] << " ";
        }
    } else {
        cout << "NO";
    }

    cout << "\n";
    x.clear();
    y.clear();
    z.clear();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        init();
    }
}