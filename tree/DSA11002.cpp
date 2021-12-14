#include <bits/stdc++.h>
using namespace std;

int toInt(string s) {
	int res = 0;
	for(int i = 0; i < s.size(); i++)
		res = res * 10 + s[i] - '0';
	return res;
}

bool isOperator(string s) {
	if(s == "+" || s == "-" || s == "*" || s == "/" || s == "^")
	   return true;
	return false;
}

int solve(int i, string *s) {
	if(isOperator(s[i])) {
		if(s[i] == "+")
			return solve(i*2+1, s) + solve(i*2+2, s);
		if(s[i] == "-")
			return solve(i*2+1, s) - solve(i*2+2, s);
		if(s[i] == "*")
			return solve(i*2+1, s) * solve(i*2+2, s);
		if(s[i] == "/")
			return solve(i*2+1, s) / solve(i*2+2, s);
	} else return toInt(s[i]);
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		string a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(0, a) << endl;
	}
}