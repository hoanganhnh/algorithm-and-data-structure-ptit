#include <bits/stdc++.h>

using namespace std;

int indexArr[100], value[100];
int n;
int sum = 0;
int temp;
bool checkNum = false;

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        indexArr[i] = j;
        temp += indexArr[i] * value[i];
        if (temp == sum /2) {
            checkNum = true;
            return;
        } 
        if (temp < sum / 2) {
            Try(i + 1);
        }
        // temp -= indexArr[i] * value[i];
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> value[i];
            sum += value[i];
        }
        if (sum % 2 != 0) {
            cout << "NO" << endl;
        } else {
            Try(1);
            if (checkNum) cout << "YES" << endl;
            else cout << "NO" << endl;
            checkNum = false;
        }
        
    }
}