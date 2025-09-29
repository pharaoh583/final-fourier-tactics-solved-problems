#include<iostream>
#include<vector>
#include<cassert>
#include<tuple>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
#define ii pair<ll, ll>
#define pb push_back
using namespace std;

ll gcd(ll a, ll b) {while(b){ll t=a%b;a=b;b=t;} return a;}
pair<ll, ll> extendedEuclid(ll a, ll b) {
    ll x, y;
    if(b == 0) return {1, 0};
    auto p = extendedEuclid(b, a%b);
    x = p.second;
    y = p.first - (a/b)*x;
    if(a*x + b*y == -gcd(a, b)) x = -x, y = -y;
    return {x, y};
}
pair<pair<ll, ll>, pair<ll, ll> > diophantine(ll a, ll b, ll r) {
    ll d = gcd(a,b);
    a/=d; b/=d; r/=d;

    auto p = extendedEuclid(a, b);
    p.first*=r; p.second*=r;
    assert(a*p.first+b*p.second == r);
    return {p, {-b, a}};
}
ll inv(ll a, ll m) {
    assert(gcd(a, m) == 1);
    ll x = diophantine(a, m, 1).first.first;
    return ((x%m) + m)%m;
} 
#define mod(a, m) (((a)%m + m)%m)
pair<ll, ll> sol(tuple<ll, ll, ll> c) {
    ll a = get<0>(c), x1 = get<1>(c), m = get<2>(c), d=gcd(a, m);
    if(d == 1) return {mod(x1*inv(a, m), m), m};
    else return x1%d ? ii({-1LL, -1LL}) : sol(make_tuple(a/d, x1/d,m/d));
}
pair<ll, ll> crt(vector<tuple<ll, ll, ll> > cond) {
    ll x1 = 0, m1 = 1, x2, m2;
    for(auto t : cond) {
        tie(x2, m2) = sol(t);
        if((x1 - x2)%gcd(m1, m2)) return {-1,-1};
        if(m1 == m2) continue;
        ll k = diophantine(m2, -m1, x1 - x2).first.second, l = m1 * (m2/gcd(m1, m2));
        x1 = mod((__int128)m1*k+x1, l); m1 = l;
    }
    return sol(make_tuple(1, x1, m1));
}
void solve() {
    ll a, n, b, m; cin>>a>>n>>b>>m;
    vector<tuple<ll, ll, ll>> cond;
    cond.pb(make_tuple(1, a, n));
    cond.pb(make_tuple(1, b, m));

    ii res = crt(cond);
    cout<<res.first<<" "<<res.second<<endl;
}

int main() {
    int t; cin>>t; 
    while(t--) solve();
}