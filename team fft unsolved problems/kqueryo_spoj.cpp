#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ii pair<int, int> 
using namespace std;

struct MSTree {
    vector<vector<int> > st; int n;

    MSTree(int n) : st(5 * n + 5), n(n) {}
    void init(int p, int l, int r, vector<int>& a) {
        if(l == r) {
            st[p].pb(a[l]);
            return;
        }
        int m = (l + r)/2;
        init(p<<1, l, m, a); init(p<<1|1, m + 1, r, a);
        int lidx = 0, ridx = 0;
        while(lidx < st[p<<1].size() and ridx < st[p<<1|1].size()) {
            if(st[p<<1][lidx] < st[p<<1|1][ridx]) {
                st[p].pb(st[p<<1][lidx++]);
            } else {
                st[p].pb(st[p<<1|1][ridx++]);
            }
        }
        while(lidx < st[p<<1].size()) st[p].pb(st[p<<1][lidx++]);
        while(ridx < st[p<<1|1].size()) st[p].pb(st[p<<1|1][ridx++]);
    }

    int query(int p, int l, int r, int a, int b, int k) {
        if(l > b or r < a) return 0;
        if(a <= l and r <= b) {
            return getGreater(p, k);
        }
        int m = (l + r)/2;
        return query(p<<1, l, m, a, b, k) + query(p<<1|1, m + 1, r, a, b, k);
    }

    int getGreater(int p, int k) {
        int l = 0, r = st[p].size() - 1;
        while(l < r) {
            int m = (l + r)/2;
            if(st[p][m] <= k) l = m + 1;
            else r = m;
        }
        if(st[p][l] <= k) return 0;
        else return st[p].size() - l;
    }

    void init(vector<int>& a) {init(1, 0, n - 1, a);}
    int query(int a, int b, int k) {
        return query(1, 0, n - 1, a, b, k);
    }
};

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    forn(i, n) cin>>a[i];
    MSTree st(n);
    st.init(a);
    int q; cin>>q;
    int prevRes = 0;
    while(q--) {
        int a, b, c; cin>>a>>b>>c; 
        
        a ^= prevRes; b ^= prevRes; c ^= prevRes;
        a--, b--;
        // cout<<a<<" "<<b<<" "<<c<<" "<<prevRes<<endl;
        int res = st.query(a, b, c);
        cout<<res<<endl;
        prevRes = res;
    }
}

int main() {
    // int t; cin>>t;

    // init();
    int t = 1;
    while(t--) solve();
}

