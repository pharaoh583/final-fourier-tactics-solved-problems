#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define 
using namespace std;

struct DSU {
  vector<int> par, sz;
  void init(int N) { sz.assign(N, 1);
    par.resize(N); iota(all(par), 0); 
  }
  int get(int x) { 
    return x == par[x] ? x : par[x] = get(par[x]);
  }
  bool sameSet(int a, int b) { return get(a) == get(b); }
  int size(int x) { return sz[get(x)]; }
  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y); 
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x; sz[x] += sz[y]; 
    return true;
  }
};

int main() {
    FastIO;

    int n, m; cin>>n>>m;
    dsu d(n);
    forn(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        d.merge(a, b);
    }

    bitset<100001> bs;
    bs[0] = 1;
    forn(i, n) {
        if(d.p[i] < 0) bs |= bs << (-d.p[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout<<bs[i];
    } cout<<endl;
}