#include<iostream>
#include<vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define vi vector<int>
using namespace std;
const int MAXI = 2e5 + 1;
vi adj[MAXI];
long long arr[MAXI];
long long dp[MAXI][2];
long long c;

void dfs(int u, int p = -1){
    
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }

    dp[u][0] = 0;
    dp[u][1] = arr[u];
    for(auto v: adj[u]){
        if(v == p) continue;
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += max(dp[v][0], dp[v][1] - 2*c);
    }
    dp[u][0] = max(dp[u][0], 0LL);
    dp[u][1] = max(dp[u][1], 0LL);
}


void solve() {
    int n; cin >> n >> c;

    forn(i, n) adj[i].clear();

    forn(i, n) cin >> arr[i];

    forn(i, n-1){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);

    cout << max(dp[0][0], dp[0][1]) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}