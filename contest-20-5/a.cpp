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

const int INF = 1e9 + 10;

#define NEUT ii(-INF, INF)
typedef ii T;
T oper(T a, T b) {
    if(a.first == b.first) {
        return ii(a.first, min(a.second, b.second));
    }
    if(a.first > b.first) return a;
    else return b;
    
}

struct STree{
    vector<T> st; int n; 
    STree(int n): st(4 * n + 5, NEUT), n(n) {}
    void init(int p, int l, int r, vector<T>& a) {
        if(l == r) {
            st[p] = a[l]; return;
        }
        int m = (l + r)/2;
        init(p<<1, l, m, a); init(p<<1|1, m + 1, r, a);
        st[p] = oper(st[p<<1], st[p<<1|1]);
    }
    void upd(int p, int l, int r, int pos, int val) {
        if(l == r) {
            st[p] = ii(val, pos); return;
        }
        int m = (l + r)/2;
        if(pos <= m) upd(p<<1, l, m, pos, val);
        else upd(p<<1|1, m + 1, r, pos, val);
        st[p] = oper(st[p<<1], st[p<<1|1]);
    }

    T query(int p, int l, int r, int a, int b) {
        if(l > b or r < a) return NEUT;
        if(a <= l and r <= b) return st[p];
        int m = (l + r)/2;
        return oper(query(p<<1, l, m, a, b), query(p<<1|1, m + 1, r, a, b));
    }
    void init(vector<T>& a){ init(1, 0, n - 1, a);}
    void upd(int p, int val) {
        upd(1, 0, n - 1, p, val);
    }
    T query(int a, int b) {
        return query(1, 0, n - 1, a, b);
    }
    void print() {
        forn(i, st.size()) {
            if(st[i].first == -INF) cout<<"-1"<<" ";
            else cout<<st[i].first<<" "; 
        }cout<<endl;
        forn(i, st.size()) {
            if(st[i].second == INF) cout<<"-1"<<" ";
            else cout<<st[i].second<<" "; 
        }cout<<endl;
    }
};


void solve() {
    int n; cin>>n;
    ll sum = 0;
    vector<ii> v(n);
    forn(i, n) {
        int a; cin>>a;
        v[i] = ii(a, i);
    }
    STree st(n);
    st.init(v);
    // st.print();

    forn(i, n) {
        if(v[i].first == 0 and i - 1 >= 0) {
            
            T val = st.query(0, i - 1);
            // cout<<"query ";
            // cout<<val.first<<" "<<val.second<<endl;
            sum += (ll)val.first;
            st.upd(val.second, 0);
            // st.print(); 
        }
    }

    cout<<sum<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
}

