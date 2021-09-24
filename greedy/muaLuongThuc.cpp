#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, s, m;
        cin >> n >> s >> m;
        int tieu_thu = s*m;
        int so_ngay_mua = s - s/7;
        int luong_mua_thuc_te = n * so_ngay_mua;
        if (tieu_thu > luong_mua_thuc_te) {
            cout << -1;
        } else {
            for (int i = 1; i <= so_ngay_mua; i++) {
                if (n*i >= tieu_thu) {
                    cout << i;
                    break;
                }
            }
        }
        cout << "\n";
    }
}