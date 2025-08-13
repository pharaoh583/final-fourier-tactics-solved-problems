//est: 7, real: 20
#include <iostream>
#include <vector>
#include <stack>
#define pb push_back
#define ii pair<int, int>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

int dp[1001][1001];
ii nxt[1000][1000];
vector<int> a, b;

int lcs(int i, int j) {
    if(i == a.size() or j == b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int maxi = 0;
    int st1 = -1, st2, st3;
    if(a[i] == b[j]) {
        st1 = 1 + lcs(i + 1, j + 1);
    }
    st2 = lcs(i + 1, j);
    st3 = lcs(i, j + 1);

    maxi = max({st1, st2, st3});
    
    if(st1 == maxi) nxt[i][j] = ii(i + 1, j + 1);
    else if(st2 == maxi) nxt[i][j] = ii(i + 1, j);
    else nxt[i][j] = ii(i, j + 1);

    return dp[i][j] = maxi;
}

int main() {
    int n, m; cin>>n>>m;
    a = vector<int>(n), b = vector<int>(m);
    forn(i, n) cin>>a[i];   
    forn(j, m) cin>>b[j];

    forn(i, n) forn(j, m) dp[i][j] = -1, nxt[i][j] = ii(-1, -1);

    cout<<lcs(0, 0)<<endl;
    int ci = 0, cj = 0;
    vector<int> v;
    while(ci < n and cj < m) {
        // cout<<ci<<" "<<cj<<endl;
        if(nxt[ci][cj].first - ci == 1 and nxt[ci][cj].second - cj == 1) {
            v.pb(a[ci]);
        }
        ii curr = nxt[ci][cj];
        ci = curr.first;
        cj = curr.second;
    }
    forn(i, v.size()) {
        cout<<v[i]<<" ";
    } cout<<endl;
}