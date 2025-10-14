#include<iostream>
#include<vector>
#define vi vector<int>
#define pb push_back
#define forn for(int i = 0; i < int(n); i++)
#define ll long long
using namespace std;

const int MAXN = 100000;

struct SegTree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

vi g[MAXN];
int wg[MAXN], dad[MAXN], dep[MAXN], cost[MAXN];
void dfs1(int x) {
    wg[x]=1;
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
    for(int y : g[x]) if(y != dad[x] and (mx < 0 or wg[mx] < wg[y])) mx=y;
    if(mx >= 0) hld(mx, c);
    for(int y:g[x]) if(y != mx and y != dad[x]) hld(y, -1);
}
void hld_init(){dad[0] = -1; dep[0] = 0; dfs1(0); curpos=0; hld(0, -1);}
ll query(int x, int y, SegTree& rmq) {
    ll r = NEUT;
    while(head[x] != head[y]) {
        if(dep[head[x]] > dep[head[y]]) swap(x, y);
        r = oper(r, rmq.query(pos[head[y]], pos[y]+1));
        y=dad[head[y]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    r = oper(r, rmq.query(pos[x], pos[y] + 1));
    return r;
}

// for creation call hld_init after reading g then create z such that z[pos[i]] = cost[i]
// init SegTree with z, then you can start doing queries
// for updating: rmq.upd(pos[x],v);
// queries on edges: - assign values of edges to "child" node
// - change pos[x] to pos[x]+1 i

int main() {
    int n, q; cin>>n>>q;
    forn(i, n - 1) {
        int a, b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn(i, n) cost[i] = 0;
    hld_init();
    
    while(q--) {
        char qtype; int a, b; cin>>a>>b; a--, b--;
        if(qtype == 'P') {

        }
    }
}

