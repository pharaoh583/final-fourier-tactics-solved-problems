#include<iostream>
#include<vector>
#define vi vector<int>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
using namespace std;

const int maxi = 3e4 + 1; 
vi g[maxi];
bool vis[maxi];

void dfs(int u) {
    for(auto v : g[u]) {
        if(!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
    cout<<u + 1<<" ";
}

void solve() {
    int n, m; cin>>n>>m;
    
    forn(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        g[a].pb(b);
    }
    

    forn(i, n) {
        if(!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    // init();
    // int t; cin>>t;
    int t = 1;
    while(t--) solve();
}