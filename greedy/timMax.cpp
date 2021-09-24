#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long sum = 0;
int  n;

void init() {
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        sum += (arr[i] * i);
        sum %= mod;
    }
}


int main() {
    int test;
    cin >> test;
    while(test--) {
        init();
        cout << sum << endl;
        sum = 0;
    }
}