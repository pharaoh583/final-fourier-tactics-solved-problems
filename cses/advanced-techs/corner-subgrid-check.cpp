#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

#include<bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
#define el '\n'
using namespace std;

int main() {
    FastIO;
    int n, k; cin>>n>>k;
    bitset<3000> m[26][n];
    string g[n];
    forn(i, n) cin>>g[i];
    int f[26][n];
    forn(i, 26) forn(j, n) f[i][j] = 0;
    vector<int> valid[26];

    forn(i, n) {
        forn(j, n) {
            m[g[i][j] - 'A'][i][j] = true;
            f[g[i][j] - 'A'][i]++;
        }
    }
    
    forn(i, 26) forn(j, n) if(f[i][j] >= 2) valid[i].pb(j);

    forn(l, k) {
        bool found = false;
        forn(i, valid[l].size()) {
            int r1 = valid[l][i];
            if(found) break;
            for(int j = i + 1; j < valid[l].size(); j++) {
                int r2 = valid[l][j];
                // cout<<(char)('A' + l)<<" "<<r1<<" "<<r2<<endl;
                if((m[l][r1]&m[l][r2]).count() >= 2) {
                    cout<<"YES"<<el;
                    found = true;
                    break;
                }
            }
        }
        if(!found) cout<<"NO"<<el;
    }
}