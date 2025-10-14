#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
#include<map>
#include<numeric>

#define FastIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define vi vector<int>
#define ii pair<int, int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
#define el '\n'
#define ll long long
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
using namespace std;

const int MAXI = 1000;
ii points[MAXI] = {};

ll abso(ll x){
    return x>0? x: -x;
}

void solve(int n){
    vector<map<long long, int>> f(n);

    forn(i, n){
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }
    int res = 0;
    forn(i, n) forn(j, n){
        ll dx = points[j].F - points[i].F;
        ll dy = points[j].S - points[i].F;
        ll d = gcd(dx, dy);
        dx /= d;
        dy /= d;
        ll m = abso(dx) | (abso(dy) << 30);
        if(dx < 0 || dy < 0) m *= -1;
        f[i][m]++;
        res = max(res, f[i][m]);
    }

    cout << res << el;
}

int main() {
    FastIO;
    int n;
    while(cin >> n && n) solve(n);
}