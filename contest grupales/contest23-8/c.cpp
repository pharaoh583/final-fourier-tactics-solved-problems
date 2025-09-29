#include<iostream>
#include<vector>
#include<cassert>
#include<tuple>
#include<set>
#include<queue>
#include<climits>
#include<algorithm>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
#define ii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
using namespace std;

struct edge{ll v, cap, inv, flow;};
struct network {
    int n, s, t;
    vector<int> lvl;
    vector<vector<edge>> g;
    network(int n) : n(n), lvl(n), g(n) {}
    void add_edge(int u, int v, ll c) {
        g[u].pb({v, c, (int)g[v].size(), 0});
        // g[v].pb({u, 0, (int)g[u].size() - 1, c});
        g[v].pb({u, c, (int)g[u].size() - 1, 0});
    }
    bool bfs() {
        fill(lvl.begin(), lvl.end(), -1);
        queue<int> q;
        lvl[s] = 0;
        for(q.push(s); q.size();q.pop() ){
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

    ll dfs(int u, ll nf) {
        if(u == t) return nf;
        ll res = 0;
        for(auto &e : g[u]) {
            if(e.cap > 0 and lvl[e.v] == lvl[u] + 1) {
                ll tf = dfs(e.v, min(nf, e.cap));
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
    ll max_flow(int so, int si, ll res = 0) {
        s = so; t = si;
        while(bfs()) res += dfs(s, LLONG_MAX);
        return res;
    }
};

int main() {
    int n, m; cin>>n>>m;
    network nt(n);
    forn(i, m) {
        int a, b; ll c; cin>>a>>b>>c; a--, b--;
        nt.add_edge(a, b, c);
    }

    // forn(i, n) {
    //     nt.g[i]
    // }

    cout<<nt.max_flow(0, n - 1)<<endl;

}