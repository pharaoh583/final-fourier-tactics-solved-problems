#include<iostream>
#include<vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define vi vector<int>
#define ll long long
using namespace std;

#define RB(x) (x < n ? r[x] : 0)

void csort(vi& sa, vi& r, int k) {
    int n = sa.size();
    vi f(max(255, n), 0), t(n);
    forn(i, n) f[RB(i + k)]++;
    int sum = 0;
    forn(i, max(255, n)) f[i] = (sum += f[i]) - f[i];
    forn(i, n) t[f[RB(sa[i] + k)]++] = sa[i];
    sa = t;
}

vi constructSA(string& s) {
    int n = s.size(), rank;
    vi sa(n), r(n), t(n);
    forn(i, n) sa[i] = i, r[i] = s[i];
    for(int k = 1; k < n; k*=2) {
        csort(sa, r, k); csort(sa, r, 0);
        t[sa[0]] = rank = 0;
        for(int i = 1; i < n; i++) {
            if(r[sa[i]] != r[sa[i - 1]] or RB(sa[i] + k) != RB(sa[i - 1] + k)) rank++;
            t[sa[i]] = rank;
        }
        r = t;
        if(r[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

vi computeLCP(string& s, vi& sa) {
    int n = s.size(), L = 0;
    vi lcp(n), plcp(n), phi(n);
    phi[sa[0]] = -1;
    forsn(i, 1, n) phi[sa[i]] = sa[i - 1];
    forn(i, n) {
        if(phi[i] < 0) {plcp[i] = 0; continue;}
        while(s[i + L] == s[phi[i] + L]) L++;
        plcp[i] = L;
        L = max(L - 1, 0);
    }
    forn(i, n) lcp[i] = plcp[sa[i]];
    return lcp;
}

int main() {
    string a; cin>>a;
    ll n = a.size();
    a += '$';
    vi sa = constructSA(a);
    vi lcp = computeLCP(a, sa);

    ll res = (n * (n + 1)) / 2;
    ll sum = 0;
    forn(i, lcp.size()) sum += (ll)lcp[i];

    cout<<res - sum<<endl;
}