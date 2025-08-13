#include<iostream>
#include<stack>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

void solve() {
    string t; 
    getline(cin, t);
    stack<char> s;
    forn(i, t.size()) {
        if(t[i] != ']' and t[i] != ')' and t[i] != '(' and t[i] != '[') continue;
        if(s.empty()) s.push(t[i]);
        else if(s.top() == '[' and t[i] == ']') s.pop();
        else if(s.top() == '(' and t[i] == ')') s.pop();
        else s.push(t[i]);
    }

    if(s.empty()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() {
    int t; cin>>t;
    string aux;
    getline(cin, aux);
    while(t--) {
        solve();
    }
}