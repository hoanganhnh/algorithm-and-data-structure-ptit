#include <bits/stdc++.h>

using namespace std;

long long n;
struct work {
    int s, f;
};
work a[1005];

bool cmp(work w1, work w2) {
    return w1.f < w2.f; // sắp xếp theo thời gian kết thúc từ bé --> lớn
}

void resolve() {
    cin >> n;
    int res = 1, temp = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i].s;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i].f;
    }

    sort(a, a + n, cmp);

    for (int i = 1; i < n; i++) {
        if (a[i].s >= a[temp].f) {
            res ++;
            temp = i;
        }
    }

    cout << res << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolve();
    }
}