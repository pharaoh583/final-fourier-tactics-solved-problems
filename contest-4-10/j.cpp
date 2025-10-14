#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

void solve(int cs) {
    int a, b, c; cin>>a>>b>>c;
    cout<<"Case "<<cs<<": ";
    if(c%__gcd(a, b) == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() {
    int t; cin>>t;
    forn(i, t){
        solve(i+1);
    }
}