#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
using namespace std;

int vis[100001];
vector<int> ciclitos;
vector<int> g[100001];

bool found = false;

void printRes(int k) {
    int n = ciclitos.size();
    cout<<k + 1<<endl;
    for(int i = n - 1; i >= n - k; i--) {
        cout<<ciclitos[i] + 1<<" ";
    } cout<<ciclitos[n - 1] + 1<<endl;
    exit(0);
}

void dfs(int u) {
    if(found) return;
    for(auto v : g[u]) {
        if(vis[v] != -1) {
            int l = ciclitos.back();
            int k = vis[l] - vis[v] + 1;
            if(k >= 3) {
                found = true;
                printRes(k);
                // return;
            }
        }
        else {
            ciclitos.pb(v);
            vis[v] = vis[u] + 1;
            dfs(v);
        }
    }
    ciclitos.pop_back();
}

void solve() {
    int n, m; cin>>n>>m;
    forn(i, n) vis[i] = -1;
    forn(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    forn(i, n) {
        if(vis[i] == -1) {
            ciclitos.pb(i);
            vis[i] = 0;
            dfs(i);
        }
    }
    if(!found) cout<<"IMPOSSIBLE"<<endl;
}

int main() {
    // int t; cin>>t;
    int t = 1;
    while(t--) {
        solve();
    }
}