#include<iostream>
#include<vector>
#include<cassert>
#include<tuple>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
#define ii pair<ll, ll>
#define pb push_back
using namespace std;


const int MAXI = 2e5+2;
int used[MAXI];
int tin[MAXI];
int low[MAXI];
int vis[MAXI];

vector<ii> adj[MAXI];
vector<ii> edges;
int dir[MAXI];

int n, m; int timer = 0; bool impossible = false;

void dfs(int u) {
    tin[u] = low[u] = timer++;
    vis[u] = true;

    // cout << "in " << u+1 <<" " << low[u] << " " << tin[u] << endl;
    for(auto [v, i]: adj[u]){
        if(used[i]) continue;
        if(vis[v]){
            // cout << "dir1 " << u+1 << " " << v+1 << " " << i <<endl;
            used[i] = true;
            dir[i] = u;
            low[u] = min(tin[v], low[u]);
            continue;
        }
        else{
            used[i] = true;
            // cout << "dir2 " << u+1 << " " << v+1 <<endl;
            dir[i] = u;
            dfs(v);
            // cout << v+1 <<  " " << low[v] << " " << tin[v] << endl;
            if(low[v] > tin[u]) impossible = true;
            low[u] = min(low[u], low[v]);
        }
        if(impossible) return;
    }
}

int main() {
    cin >> n >> m;
    forn(i, m){
        int u, v; cin>> u >> v;
        u--; v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        edges.pb({u, v});
    }

    fill(vis, vis+n, false);
    fill(used, used+m, false);
    fill(dir, dir+m, -1);
    fill(low, low+n, MAXI);
    fill(tin, tin+n, 0);
    
    dfs(0);
    forn(i, n) if(!vis[i]) impossible = true;

    // forn(i, m) cout << dir[i] << "  "; cout << endl;


    if(impossible){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        forn(i, m){
            int a = dir[i];
            int b = (a == edges[i].first)? edges[i].second: edges[i].first;
            cout << a+1 << " " << b+1 << endl;
        }
    }
    
}