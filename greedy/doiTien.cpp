#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> money = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
vector<int> count_money;
int n = 0;
int value;

void resolve() {
    cin >> value;
    sort(money.begin(), money.end());
    for (int i = money.size() - 1; i >= 0; i--) {
        while ( money[i] <= value && value != 0) {
            value -=  money[i];
            n++;
            count_money.push_back(money[i]);
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        resolve();
        cout << n << endl;
        count_money.clear();
        n = 0;
    }
}