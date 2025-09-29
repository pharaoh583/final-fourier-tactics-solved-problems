#include<iostream>
#include<vector>
#include<cassert>
#include<tuple>
#include<set>
#include<queue>
#include<algorithm>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
#define ii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
using namespace std;

const int maxn = 1e6;

vi g[maxn], rg[maxn], cdg[maxn];
bool vis[maxn];
int id[maxn];

ll cost[maxn];
ll dp[maxn];
ll f[maxn];
int cnt = 0;

vi tpsrt;

set<ii> edges;

void dfs1(int u) {
    for(auto v : g[u]) {
        if(!vis[v]) {
            vis[v] = true;
            dfs1(v);
        }
    }
    tpsrt.pb(u);
}

void dfs2(int u) {
    for(auto v: rg[u]) {
        if(id[v] == -1) {
            cost[cnt] += f[v];
            id[v] = cnt;
            dfs2(v);
        }
    }
}

void dfs3(int u) {
    for(auto v: cdg[u]) {
        if(!vis[v]) {
            vis[v] = true;
            dfs3(v);
        }
    }
    tpsrt.pb(u);
}

int main() {
    int n, m, s, e; cin>>n>>m>>s>>e; s--, e--;

    forn(i, n) cin>>f[i], vis[i] = 0, id[i] = -1, cost[i] = 0, dp[i] = 0;
    cnt = 0;
    forn(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        rg[b].pb(a);
    }

    forn(i, n) {
        if(!vis[i]) dfs1(i);
    }
    // forn(i, n) cout<<tpsrt[i]<<" "; cout<<endl;
    reverse(all(tpsrt));
    forn(i, n) {
        if(id[tpsrt[i]] == -1) {
            id[tpsrt[i]] = cnt;
            cost[cnt] += f[tpsrt[i]];
            dfs2(tpsrt[i]);
            cnt++;
        }
    }

    forn(i, n) {
        for(auto v : g[i]) {
            if(id[i] != id[v] and !edges.count(ii(id[i], id[v]))) {
                edges.insert(ii(id[i], id[v]));
                cdg[id[i]].pb(id[v]);
            }
        }
    }
    s = id[s];
    e = id[e];
    dp[s] = cost[s];
    forn(i, cnt) vis[i] = false;
    if(s == e) cout<<cost[s]<<endl;
    else {
        // cout<<s<<endl;
        tpsrt.clear();
        dfs3(s);
        reverse(all(tpsrt));
        // forn(i, tpsrt.size()) cout<<tpsrt[i]<<" "; cout<<endl;
        for(auto u : tpsrt) {
            for(auto v : cdg[u]) {
                dp[v] = max(dp[v], dp[u] + cost[v]);
            }
        }        
        cout<<dp[e]<<endl;
    }

}