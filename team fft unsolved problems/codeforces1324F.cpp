#include<iostream>
#include<vector>
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define vi vector<int>
#define pb push_back
using namespace std;

const int maxn = 2e5 + 1;
int color[maxn];
int p[maxn];
int dp1[maxn];
int dp2[maxn];

vi g[maxn];

void dfs(int u) {
    int maxi = (color[u] ? 1 : -1);
    for(auto v : g[u]) {
        if(p[v] == -1 and v != p[u]) {
            p[v] = u;
            dfs(v);
            if(dp1[v] > 0) maxi += dp1[v];
        }
    }
    dp1[u] = maxi;
}

void dfs2(int u) {
    int maxi = dp1[u];
    if(p[u] != -1) {
        int parentValue = dp2[p[u]];
        if(dp1[u] > 0) parentValue -= dp1[u];
        maxi += (parentValue > 0 ? parentValue : 0);
    }
    dp2[u] = maxi;
    for(auto v : g[u]) {
        if(p[u] != v) {
            dfs2(v);
        }
    }
}

int main() {
    int n; cin>>n;
    forn(i, n) cin>>color[i];
    forn(i, n - 1) {
        int a, b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn(i, n) {
        dp1[i] = 0;
        dp2[i] = 0;
        p[i] = -1;
    }

    dfs(0);
    // forn(i, n) cout<<dp1[i]<<" "; cout<<endl;
    dfs2(0);

    forn(i, n) cout<<dp2[i]<<" "; cout<<endl;
}