#include<iostream>
#include<vector>
#include<map>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define vi vector<int>
#define ll long long
#define ii pair<int, int> 
#define el '\n'
using namespace std;

#define NEUT (-1e14)
typedef ll T;
T oper(T a, T b) {return max(a, b);}
struct SegTree {
    vector<T> st; int n;
    SegTree(int n) : st(4 * n + 5, NEUT), n(n) {}
    void init(int p, int l, int r, vector<T>& a) {
        if(l == r) {st[p] = a[l]; return;}
        int m = (l + r)/2;
        init(p<<1, l, m, a); init(p<<1|1, m + 1, r, a);
        st[p] = oper(st[p<<1], st[p<<1|1]);
    }
    void upd(int p, int l, int r, int pos, T val) {
        if(l == r) {st[p] = val; return;}
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
    void init(vector<T>& a){init(1, 0, n - 1, a);}
    void upd(int p, T val){upd(1, 0, n - 1, p, val);}
    T query(int a, int b) {return query(1, 0, n - 1, a, b);}
};

const int MAXN = 10000;
vi g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN];
void dfs1(int x) {
    wg[x] = 1;
    for(int y : g[x]) if(y != dad[x]) {
        dad[y] = x; dep[y] = dep[x] + 1; dfs1(y);
        wg[x] += wg[y];
    }
}
int curpos, pos[MAXN], head[MAXN];
void hld(int x, int c) {
    if(c < 0) c = x;
    pos[x] = curpos++; head[x] = c;
    int mx = -1;
    for(int y : g[x]) if(y != dad[x] and (mx < 0 or wg[mx] < wg[y])) mx = y;
    if(mx >= 0) hld(mx, c);
    for(int y : g[x]) if(y != mx and y != dad[x]) hld(y, -1);
}
void hld_init(){dad[0]=-1; dep[0] = 0; dfs1(0); curpos = 0; hld(0, -1);}
ll query(int x, int y, SegTree& rmq) {
    ll r = NEUT;
    while(head[x] != head[y]) {
        if(dep[head[x]] > dep[head[y]]) swap(x, y);
        r = oper(r, rmq.query(pos[head[y]], pos[y]));
        y = dad[head[y]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    r = oper(r, rmq.query(pos[x] + 1, pos[y]));
    return r;
}

int a[MAXN], b[MAXN], c[MAXN];

int getEndNode(ii edge) {
    if(dad[edge.first] == edge.second) return edge.first;
    else return edge.second;
}

void solve() {
    int n; cin>>n;
    forn(i, n) g[i].clear();
    
    map<ii, int> idx;
    forn(i, n - 1) {
        cin>>a[i]>>b[i]>>c[i]; a[i]--, b[i]--;
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }

    hld_init();
    vector<ll> z(n);
    z[0] = NEUT;
    forn(i, n - 1) {
        int endNode = getEndNode(ii(a[i], b[i]));
        z[pos[endNode]] = c[i];
    } 
    SegTree st(n); st.init(z);

    while(true) {
        string qtype; cin>>qtype;
        if(qtype == "DONE") return;
        if(qtype == "QUERY") {
            int a, b; cin>>a>>b; a--, b--;
            cout<<query(a, b, st)<<el;
        } else {
            int i, ti; cin>>i>>ti; i--;
            int endNode = getEndNode(ii(a[i], b[i]));
            st.upd(pos[endNode], ti);
        }
    }
}

int main() {
    FastIO;
    int t; cin>>t;
    while(t--) solve();
}