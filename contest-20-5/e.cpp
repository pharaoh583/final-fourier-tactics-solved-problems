#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ii pair<int, int> 
#define F first
#define S second
using namespace std;


const int MAXI = 1e5 + 1;

vector<int> primes;
int sieve[MAXI];
int arr[2001];
int n;

void init(){
    sieve[0] = sieve[1] = 1;
    forn(i, MAXI){
        if(sieve[i] == 0){
            sieve[i] = i;
            primes.pb(i);
        }
        for(int j = 0; j < primes.size() and 1LL*i*primes[j] < MAXI; j++){
            sieve[i*primes[j]] = primes[j];
            if(primes[j] == sieve[i]) break;
        }
    }
}


struct edge { int v, cap,  inv, flow;};
struct network {
    public:
    int n, s, t; 
    vector<int> lvl;
    vector<vector<edge>> g;
    network(int n) : n(n), lvl(n), g(n) {}
    void add_edge(int u, int v, int c) {
        g[u].pb({v, c, (int)g[v].size(), 0});
        g[v].pb({u, 0, (int)g[u].size() - 1, c});
    }

    bool bfs() {
        fill(all(lvl), -1);
        queue<int> q;
        lvl[s] = 0;
        for(q.push(s); q.size(); q.pop()) {
            int u = q.front();
            for(auto &e : g[u]) {
                if(e.cap > 0 and lvl[e.v] == -1) {
                    lvl[e.v] = lvl[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return lvl[t] != -1;
    }
    int dfs(int u, int nf) {
        if(u == t) {
            return nf;
        }
        int res = 0;
        for(auto &e : g[u]) {
            if(e.cap > 0 and lvl[e.v] == lvl[u] + 1) {
                int tf = dfs(e.v, min(nf, e.cap));
                res += tf; nf -= tf; e.cap -= tf;
                g[e.v][e.inv].cap += tf;
                g[e.v][e.inv].flow -= tf;
                e.flow += tf;
                if(nf == 0) return res;
            }
        }
        if(!res) lvl[u] = -1;
        return res;
    }
    int max_flow(int so, int si, int res = 0) {
        s = so; t = si;
        while(bfs()) res += dfs(s, INT_MAX);
        return res;
    }
    vector<ii> minCut() {
        bfs();
        vector<ii> mc;
        forn(i, n) {
            if(lvl[i] == -1) continue;
            for(auto &e : g[i]) {
                if(lvl[e.v] == -1) {
                    mc.pb({i, e.v});
                }
            }
        }
        return mc;
    }
};

void solve() {
    cin >> n; 
    forn(i, n) cin >> arr[i];
    
    auto nt = network(n+2);
    forn(i, n){
        forn(j, n){
            if(i == j) continue;
            int a = arr[i];
            int b = arr[j];
            if(sieve[a+b] == a+b){
                nt.add_edge(i, j, 1);
            }
        }
    }

    forn(i, n){
        if(arr[i]%2 == 0){
            nt.add_edge(n, i, 1);
        }
        else{
            nt.add_edge(i, n+1, 1);
        }
    }

    nt.max_flow(n, n+1);
    auto minCutRes = nt.minCut();
 
    vector<int> res;
    for(auto p: minCutRes){
        if(nt.g[p.F].size() > nt.g[p.S].size()){
            res.pb(arr[p.F]);
        }
        else{
            res.pb(arr[p.S]);
        }

        
    }

    cout << res.size() << endl;
    for(auto e: res) cout << e << " ";
    cout << endl;
}

int main() {
    // int t; cin>>t;
    int t = 1;
    init();
    while(t--) solve();
}

