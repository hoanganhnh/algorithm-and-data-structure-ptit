#include <bits/stdc++.h>
using namespace std;

stack<long long> value;
stack<char> character;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

long long caculator(long long a, long long b, char c) {
    switch (c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

void update() {
    long long a = value.top();
    value.pop();
    long long b = value.top();
    value.pop();
    char c = character.top();
    character.pop();
    value.push(caculator(b, a, c));
}

void handle(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            character.push(s[i]);
        } else if (isdigit(s[i])) {
            int x = 0;
            while (i < n && isdigit(s[i])) {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            if (!isdigit(s[i])) {
                i--;
            }
            value.push(x);
        } else if (s[i] == ')') {
            while (!character.empty() && character.top() != '(' ) {
                update();
            }
            if (!character.empty()) character.pop();
        } else {
            while (!character.empty() &&  priority(character.top()) >= priority(s[i])) {
                update();
            }
            character.push(s[i]);
        }
    }
    while (!character.empty()) {
        update();
    }
    cout << value.top() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        handle(s);
    }
}