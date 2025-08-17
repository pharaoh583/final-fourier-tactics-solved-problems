#include <iostream>
#include <vector>
#include <map>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
using namespace std;

int dp[1<<16][16];
bool g[16][16];
int n; 
int maxAdd(int mask, int last) {
    if(dp[mask][last] != -1) return dp[mask][last];
    int maxi = __builtin_popcount(mask);

    forn(v, n) {
        if(!g[last][v]) continue;
        if((mask&(1<<v)) == 0) maxi = max(maxi, maxAdd(mask|(1<<v), v));
    }
    return dp[mask][last] = maxi;
}

void init(int n) {
    forn(i, 1<<n) forn(j, n) dp[i][j] = -1;
    forn(i, n) forn(j, n) g[i][j] = false;
}

void solve() {
    cin>>n;
    init(n);
    map<string, vector<int> > gn;
    map<string, vector<int> > a;
    forn(i, n) {
        string genre, artist;
        cin>>genre>>artist;
        gn[genre].push_back(i);
        a[artist].push_back(i);
    }

    for(auto [k, v] : gn) {
        forn(i, v.size()) {
            forsn(j, i + 1, v.size()) {
                g[v[i]][v[j]] = true;
                g[v[j]][v[i]] = true;
            }
        }
    }
    for(auto [k, v] : a) {
        forn(i, v.size()) {
            forsn(j, i + 1, v.size()) {
                g[v[i]][v[j]] = true;
                g[v[j]][v[i]] = true;
            }
        }
    }

    int maxi = 0;
    forn(i, n) {
        maxi = max(maxi, maxAdd(1<<i, i));
    }
    cout<<n - maxi<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
    return 0;
}