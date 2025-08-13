#include<iostream>
#include<stack>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

void solve() {
    int a, b; cin>>a>>b;
    cout<<__lcm(a, b)<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}