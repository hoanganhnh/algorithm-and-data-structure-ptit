#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string numbers[2];
vector<int> sum_numbers;

void init() {
    for (int i = 0; i < 2; i++) {
        cin >> numbers[i];
    }
}

int sum(int a, int b) {
    return a + b;
}

void resolve() {
    for (int i = 0; i < 2; i++) {
        string a = numbers[i];
        for (int i = 0; i < a.length(); i++ ) {
            if (a[i] == '6') {
                a[i] = '5';
            }
        }
        numbers[i] = a;
    }
    int res1 = sum(std::stoi(numbers[0]), std::stoi(numbers[1]));
    sum_numbers.push_back(res1);
    for (int i = 0; i < 2; i++) {
        string a = numbers[i];
        for (int i = 0; i < a.length(); i++ ) {
            if (a[i] == '5') {
                a[i] = '6';
            }
        }
        numbers[i] = a;
        
    }
    int res2 = sum(stoi(numbers[0]), stoi(numbers[1]));
    sum_numbers.push_back(res2);
}

int main() {
    int test;
    // cin >> test;
        init();
        resolve();
        for (int i = 0; i < sum_numbers.size(); i++ ) {
            cout << sum_numbers[i] << " "; 
        }
        cout << endl;
        sum_numbers.clear();
}