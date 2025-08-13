#include<iostream>
#include<vector>
#include<iomanip>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
using namespace std;

vector<int> g[100'000];

double dfs(int u, int d, double p, int dad) {
    // cout<<"dfs("<<u<<","<<d<<","<<p<<","")"
    double exp = 0;
    int s = (dad == -1 ? g[u].size() : g[u].size() - 1);

    if(dad != -1 and s == 0) {
        return p * d;
    }

    for(auto v : g[u]) {
        if(v == dad) continue;
        exp += dfs(v, d + 1, p * 1.0000000/(double)(s), u);
    }
    return exp;
}



int main() {
    int n; cin>>n;
    forn(i, n - 1) {
        int u, v; cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    cout<<fixed<<setprecision(7)<<dfs(0, 0, 1.00000000, -1)<<endl;
}