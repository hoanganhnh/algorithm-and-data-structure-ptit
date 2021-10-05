#include<iostream>

using namespace std;
string n, m;
int k;
void heCoSoK() {
    int bienNho = 0;
    string result = "";
    while (n.length() < m.length()) n = "0" + n;
    while (n.length() > m.length()) m = "0" + m;
    for (int i = n.length() - 1; i >= 0; i--) {
        int tmp1 = n[i] - '0';
        int tmp2 = m[i] - '0';
        int sum = tmp1 + tmp2 + bienNho;
        result = char(sum % k + '0') + result;
        bienNho = sum / k;
    }
    if (bienNho > 0) result = char(bienNho + '0') + result;
    cout << result << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> k >> n >> m;
        heCoSoK();
    }
}