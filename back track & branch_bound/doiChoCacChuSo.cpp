#include <iostream>
#include <algorithm>

using namespace std;

string s;
int k;

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin  >> k >> s;
        int indexMax = s.size() - 1;
        for (int i = 0; i <= indexMax; i++) {
            char max = s[indexMax];
            int index = indexMax;
            for (int j = indexMax - 1; j > i && k > 0; j--) {
                if (max < s[j]) {
                    max = s[j];
                    index = j;
                }
            }
            if (max > s[i] && k > 0) {
                swap(s[i], s[index]);
                k--;
            }
        }

        cout << s << endl;
    }
}