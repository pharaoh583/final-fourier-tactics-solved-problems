#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n;
    int q; cin>>q;
    ll p[n + 1]; p[0] = 0;
    ll a[n]; forn(i, n) cin>>a[i], p[i + 1] = p[i] + a[i];
    ll total = p[n];
    while(q--) {
        int l, r; cin>>l>>r;
        ll k; cin>>k;

        ll sum = total - (p[r] - p[l - 1]) + k * (ll)(r - l + 1);
        if(sum%2 == 0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}

int main() {
    int t; cin>>t; 
    while(t--) solve();
}