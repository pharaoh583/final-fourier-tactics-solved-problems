//#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<algorithm>
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
#define ll long long
using namespace std;

const double EPS = 1e-9;

struct pt {
    ll x, y;
    pt(ll x, ll y):x(x),y(y){}
    pt() {}
    ll norm2() {return *this**this;}
    bool operator==(pt p) {return x == p.x and y == p.y; }
    pt operator+(pt p) {return pt(x + p.x, y + p.y);}
    pt operator-(pt p) {return pt(x - p.x, y - p.y);}
    pt operator*(ll t) {return pt(x*t, y*t);}
    ll operator*(pt p) {return x * p.x + y * p.y;}
    ll operator%(pt p) {return x * p.y - y * p.x;}
    bool operator<(pt p)const{ // for convex hull
		return x<p.x||x==p.x&&y<p.y;}
    bool left(pt p, pt q) {
        return (q - p)%(*this-p) >= 0;
    }
};

struct pol {
    int n; vector<pt> p;
    pol() {}
    pol(vector<pt> _p) {p = _p; n = p.size();}
    ll callipers() {
        ll r = 0;
        for(int i = 0, j = n < 2 ? 0 : 1; i < j; i++) {
            for(;;j = (j + 1)%n) {
                r = max(r, (p[i] - p[j]).norm2());
                if((p[(i + 1)%n] - p[i])%(p[(j + 1)%n] - p[j]) <= 0) break;
            }
        }
        return r;
    }
};

vector<pt> chull(vector<pt> p){
	vector<pt> r;
	sort(p.begin(),p.end()); // first x, then y
	forn(i,p.size()){ // lower hull
		while(r.size()>=2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=r.size();
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(r.size()>=k+2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}

void solve() {
    int n; cin>>n;
    vector<pt> p;
    forn(i, n) {
        ll x, y; cin>>x>>y;
        p.pb(pt(x, y));
    }
    p = chull(p);
    pol pl(p);
    cout<<pl.callipers()<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
}