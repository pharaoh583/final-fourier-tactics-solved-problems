#include<iostream>
#include<algorithm>
#include<vector>
#include <map>
#include<queue>
#define vi vector<int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define pb push_back 
#define all(x) (x).begin(),(x).end()
using namespace std;

const int MAXI = 2e5 + 1;
vector<int> adj[MAXI];
ll arr[MAXI];
int n_size[MAXI];
int n_depth[MAXI];
int n_maxi[MAXI];
int n; int min_turn = MAXI; ll max_kill = 0;

void pre_dfs(int u, int p = -1, int d = 0){
    n_size[u] = 1;
    n_depth[u] = d;
    n_maxi[u] = -1;

    for(auto v: adj[u]){
        if(v == p) continue;
        pre_dfs(v, u, d + 1);
        n_size[u] += n_size[v];
        if(n_maxi[u] == -1) n_maxi[u] = v;
        else if(n_size[v] > n_size[n_maxi[u]]) n_maxi[u] = v;
    }
}

void dfs(int u, map<int, ll>& sum, int p = -1, int d = 0){
    sum[d] = arr[u];
    if(sum[d] > max_kill){
        max_kill = sum[d];
        min_turn = 0;
    }
    else if(sum[d] == max_kill) min_turn = 0;

    if(n_maxi[u] != -1) dfs(n_maxi[u], sum, u, d + 1);
    for(auto v: adj[u]){
        if(v == p || v == n_maxi[u]) continue;
        map<int, ll> aux_sum;
        dfs(v, aux_sum, u, d + 1);

        for(auto it: aux_sum){
            sum[it.first] += it.second;
            if(sum[it.first] > max_kill){
                max_kill = sum[it.first];
                min_turn = it.first - d;
            }
            else if(sum[it.first] == max_kill){
                min_turn = min(min_turn, it.first - d);
            } 
        }
    }
}

int main() {
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    int n; cin>>n;

    arr[0] = 0;
    forn(i, n - 1) {
        cin>>arr[i + 1];
    }

    forn(i, n - 1) {
        int a, b; cin>>a>>b; a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    pre_dfs(0);

    for(auto v: adj[0]){
        auto sum = map<int, ll>();
        dfs(v, sum, 0, 1);
    }
    

    cout << max_kill << " " << min_turn+1 << endl;
}