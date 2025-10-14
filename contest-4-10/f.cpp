#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

void solve() {
    int a; cin>>a;
    cout<<__builtin_popcount(a)<<endl;
}

int main() {
    // int t; cin>>t;
    int t = 1;
    forn(i, t){
        solve();
    }
}