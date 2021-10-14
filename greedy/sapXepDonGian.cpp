#include <bits/stdc++.h>

using namespace std;
/**
 *@FIXME
*/

int n;

int longest_increasing_subsequence(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end()) {
            ans.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }
    return ans.size();
}

void resolve() {
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    int res = longest_increasing_subsequence(a);
    cout << n - res << endl;
}

int main() {
    resolve();
}