#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
using namespace std;
const ll M = 1e9 + 7;

ll modExp(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    ll z = modExp(a, b/2);

    if(b%2 == 0) return (z * z)%M;
    return ((z * z)%M * a)%M;
}

void solve() {
    ll n; cin>>n;
    ll sum = 0;
    ll a[n];
    forn(i, n) {
        cin>>a[i]; sum += a[i];
    }
    sum %= M;

    ll t = 0;
    forn(i, n) {
        sum = (sum - a[i] + M)%M;
        t = (t + (sum * a[i])%M)%M;
    }

    t = (t * 2)%M;
    cout<<(t * modExp((n * (n - 1))%M, M - 2))%M<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();

}