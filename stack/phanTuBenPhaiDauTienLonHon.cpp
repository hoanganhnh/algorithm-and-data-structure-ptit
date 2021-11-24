#include<bits/stdc++.h>

using namespace std;

void nextRightGreater(int a[], int n, int storeIdx[]) {/* c2 */
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            storeIdx[i] = st.top();
        } else {
            storeIdx[i] = -1;
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (storeIdx[i] != -1)
            cout << a[storeIdx[i]] << " ";
        else 
            cout << -1 << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        stack<int> st;

        for (int &x: a) cin >> x;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(i);
            } else {
                while (!st.empty() && a[st.top()] < a[i]) {
                    b[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }

        while (!st.empty()) {
            b[st.top()] = -1;
            st.pop();
        }

        for (int x: b) cout << x << " ";

        cout << endl;
    }
}
