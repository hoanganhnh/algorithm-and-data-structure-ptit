#include <bits/stdc++.h>
using namespace std;
bool check(string s){
    if (s.size() == 0) return true;
    stack <char> st;
    for (int i=0;i<s.size();i++){
        if (s[i] == ']' && st.empty() || (s[i] == ')' && st.empty()) || (s[i] == '}' && st.empty()) ) return false;
        else {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else {
                    if (s[i] == ')' && st.top() =='(') st.pop(); 
                    else if (s[i] == ']' && st.top() =='[') st.pop();
                    else if (s[i] == '}' && st.top() =='{') st.pop();
                    else return false;
            }
        }
    }
    if (st.size() >0 ) return false;
    return true;
}
main (){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if (check(s)) cout <<"true"<<endl;
        else cout << "false" <<endl;
    }
}