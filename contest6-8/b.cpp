#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#define all(v) (v).begin(), (v).end()
#define ll long long
#define pb push_back
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

typedef ll tf;
typedef ll tc;
const tf INFFLOW = 1e9;
const tc INFCOST = 1e9;

struct MCF {
    int n; 
    vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge, prevnode;
    priority_queue<pair<tc, int>, vector<pair<tc, int> >, greater<pair<tc, int> > > q;
    struct edge{int to, rev; tf f, cap; tc cost;};

    vector<vector<edge>> g;
    MCF(int n) : n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
    void add_edge(int s, int t, tf cap, tc cost) {
        g[s].pb((edge){t,(int)g[t].size(), 0, cap, cost});
        g[t].pb((edge){s,(int)g[s].size() - 1, 0, 0, -cost});
    }

    pair<tf, tc> get_flow(int s, int t) {
        tf flow=0; tc flowcost = 0;
        while(true) {
            q.push({0,s});
            fill(all(prio), INFCOST);
            prio[s]=0;curflow[s]=INFFLOW;
            while(!q.empty()) {
                auto cur=q.top();
                tc d = cur.F;
                int u = cur.S;
                q.pop();
                if(d != prio[u]) continue;
                forn(i, g[u].size()) {
                    edge &e=g[u][i];
                    int v = e.to;
                    if(e.cap <= e.f) continue;
                    tc nprio=prio[u]+e.cost+pot[u]-pot[v];
                    if(prio[v] > nprio) {
                        prio[v] = nprio;
                        q.push({nprio, v});
                        prevnode[v] = u; prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if(prio[t] == INFCOST) break;
            forn(i, n) pot[i] += prio[i];
            tf df=min(curflow[t], INFFLOW-flow);
            flow += df;
            for(int v = t; v != s; v=prevnode[v]) {
                edge &e = g[prevnode[v]][prevedge[v]];
                e.f += df; g[v][e.rev].f -= df;
                flowcost += df * e.cost;
            }
        }
        return {flow, flowcost};
    }
};

void solve() {
    int n; cin>>n;
    int s = 0, t = 2 * n + 1;
    int firstRow = 1, firstCol = n + 1;
    MCF nt(2 * n + 2);

    int r[n], c[n]; 
    int sr = 0, sc = 0;
    forn(i, n) cin>>r[i], sr += r[i], nt.add_edge(s, i + firstRow, r[i], 0);
    forn(i, n) cin>>c[i], sc += c[i], nt.add_edge(i + firstCol, t, c[i], 0);

    forn(i, n) {
        forn(j, n) {
            int a; cin>>a; nt.add_edge(i + firstRow, j + firstCol, 1, -a);
        }
    }

    if(sr != sc) {
        cout<<-1<<endl; return;
    }

    pair<tf, tc> res = nt.get_flow(s, t);

    if(res.first != sr) {
        cout<<-1<<endl; return;
    }
    cout<<-res.second<<endl;
    char m[n][n];
    forn(i, n) forn(j, n) m[i][j] = '.';
    forn(i, n) {
        for(auto &e : nt.g[i + firstRow]) {
            if(e.to > n and e.f == e.cap) {
                m[i][e.to - firstCol] = 'X';
            }
        }
    }

    forn(i, n) {
        forn(j, n) cout<<m[i][j];
        cout<<endl;
    }
}

int main() {
    int t = 1;
    while(t--) solve();
}