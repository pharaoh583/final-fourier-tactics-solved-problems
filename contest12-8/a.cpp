#include<iostream>
#include<stack>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

int modExp(int a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    int z = modExp(a, b/2);
    if(b%2 == 0) return (z * z)%10;
    else return ((z * z)%10 * a)%10;
}

void solve() {
    int a; ll b; cin>>a>>b;

    cout<<modExp(a, b)<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}