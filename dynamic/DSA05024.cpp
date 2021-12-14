#include <iostream>
using namespace std;
int mod = 1000000000+7;

int solve(int *a, int n, int k) {
	int c[k+1] = {1};
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < n; j++) {
			if(a[j] <= i)
				c[i] = (c[i] + c[i-a[j]]) % mod;
		}
	}
	return c[k];
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, k; cin >> n >> k;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(a, n, k) << endl;
	}
}
