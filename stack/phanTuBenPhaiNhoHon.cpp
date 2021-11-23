#include<bits/stdc++.h>

using namespace std;

const int MAX = 100005;

void nextGreater(int n, int a[], int G[]) {
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            G[i] = st.top();
        } else {
            G[i] = -1;
        }
        st.push(i);

    }
}
void rightSmaller(int n, int a[], int S[]) {
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            S[i] = st.top();
        } else {
            S[i] = -1;
        }
        st.push(i);
    }
}
void handle(int a[], int n) {
    stack<int> st;
    int G[MAX], S[MAX];
    nextGreater(n, a, G);
    rightSmaller(n, a, S);
    for (int i = 0; i < n; i++) {
        int indxRightGreater = G[i];
        int indxRightSmaller = S[indxRightGreater];
        if (indxRightGreater != -1 && indxRightSmaller != -1) {
            cout << a[indxRightSmaller] << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int &x: a) cin >> x;
        handle(a, n);
    }
}
