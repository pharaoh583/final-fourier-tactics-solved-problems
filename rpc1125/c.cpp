#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
using namespace std;

struct edge{int v, cap, inv, flow;};
struct network {
    int n, s, t;
    vector<int> lvl;
    vector<vector<edge>> g;
    network(int n) : n(n), lvl(n), g(n) {}
    void add_edge(int u, int v, int c) {
        g[u].pb({v, c, (int)g[v].size(), 0});
        g[v].pb({u, 0, (int)g[u].size() - 1, c});
    }
    bool bfs() {
        fill(lvl.begin(), lvl.end(), -1);
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
        if(u == t) return nf;
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
};

int main() {
    int n; cin>>n;
    int a[n];
    int sum = 0;
    forn(i, n) cin>>a[i], sum += a[i];
    int teams = sum/3;

    int nodes = teams + n + 2;
    int s = nodes - 2, t = nodes - 1;
    int firstDuck = 0;
    int firstTeam = n;
    network nt(nodes); //nodes - 2 = source, nodes - 1 = sink
    forn(i, n) {
        nt.add_edge(s, i, a[i]);
    }
    forn(i, teams) {
        nt.add_edge(i + firstTeam, t, 3);
    }
    forn(i, n) {
        forn(j, teams) {
            nt.add_edge(i, j + firstTeam, 1);
        }
    }
    int mf = nt.max_flow(s, t);
    if(mf == sum) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
}