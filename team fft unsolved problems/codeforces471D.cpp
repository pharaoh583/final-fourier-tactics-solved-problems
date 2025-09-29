#include<iostream>
#include<vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int> 
#define pb push_back
using namespace std;

vi z_function(vi& s) {
    int l = 0, r = 0, n = s.size();
    vi z(n, 0);
    forsn(i, 1, n) {
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    int n, m; cin>>n>>m;
    vi s(n), p(m);
    forn(i, n) cin>>s[i];
    forn(i, m) cin>>p[i];

    vi sq;
    forsn(i, 1, m) sq.pb(p[i] - p[i - 1]);
    sq.pb((int)1e9 + 10);
    forsn(i, 1, n) sq.pb(s[i] - s[i - 1]);

    vi z = z_function(sq);
    int cont = 0;
    forn(i, sq.size()) {
        if(z[i] == m - 1) cont++;
    } 
    cout<<cont<<endl;
}