#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

struct edge {int v, cap, inv, flow;};
struct network {
    int n, s, t;
    vector<int> lvl;
    vector<vector<edge>> g;
    network(int n): n(n), lvl(n), g(n) {}

    void add_edge(int u, int v, int c) {
        g[u].push_back({v, c, (int)g[v].size(), 0});
        g[v].push_back({u, 0, (int)g[u].size() - 1, c});
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
        s = so;
        t = si;
        while(bfs()) res += dfs(s, INT_MAX);
        return res;
    }
};

int main() {
    int n; cin>>n;
    int r[n], c[n];

    int s = 0, t = 2 * n + 1;

    network nt(2 * n + 2);

    int firstRow = 1, firstCol = n + 1;
    int sr = 0, sc = 0;
    forn(i, n) cin>>r[i], nt.add_edge(0, i + firstRow, r[i]), sr += r[i];
    forn(i, n) cin>>c[i], nt.add_edge(i + firstCol, t, c[i]), sc += c[i];

    if(sr != sc) {
        cout<<-1<<endl;
        return 0;
    }

    forn(i, n) {
        forn(j, n) {
            nt.add_edge(i + firstRow, j + firstCol, 1);
        }
    }

    int mf = nt.max_flow(s, t);
    if(mf != sr) {
        cout<<-1<<endl;
        return 0;
    }

    char m[n][n];
    forn(i, n) forn(j, n) m[i][j] = '.';
    forn(i, n) {
        for(auto &e : nt.g[i + firstRow]) {
            if(e.v > n and e.cap == 0) {
                m[i][e.v - firstCol] = 'X';
            }
        }
    }

    forn(i, n) {
        forn(j, n) cout<<m[i][j];
        cout<<endl;
    }
}