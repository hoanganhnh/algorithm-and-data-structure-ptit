#include <bits/stdc++.h>

using namespace std;
const int infi = 1e9;
const int MAX = 100005;
int n, a[MAX], R[MAX], L[MAX];

void nextRightSmaller() {
    stack<int> st;
    a[n + 1] = infi;
    st.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            R[i] = st.top();
        } else {
            R[i] = n + 1;
        }
        st.push(i);
    }
    
}

void nextLeftSmaller() {
    stack<int> st;
    a[0] = infi;
    st.push(0);
    for (int i = 1;i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            L[i] = st.top();
        } else {
            L[i] = 0;
        }
        st.push(i);
    }
   
}

void handle() {
    nextLeftSmaller();
    nextRightSmaller();
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        long long area = 1LL*a[i]*(R[i] - L[i] - 1);
        res = max(res, area);
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        handle();
    }
} 