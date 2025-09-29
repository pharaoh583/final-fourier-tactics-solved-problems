#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
using namespace std;

const ll M = 100000007;

ll modPow(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    ll z = modPow(a, b/2);

    if(b%2 == 0) return (z * z)%M;
    else return ((z * z)%M * a)%M;
}

void solve(int c) {
    int n; cin>>n;
    ll sum = 0;
    forn(i, n) {
        ll a; cin>>a;
        sum = (sum + a)%M;
    }
    cout<<"Case "<<c<<": "<<(sum * modPow(2, n - 1))%M<<endl;
}

int main() {
    int t; cin>>t;
    forn(i, t) solve(i + 1);
}