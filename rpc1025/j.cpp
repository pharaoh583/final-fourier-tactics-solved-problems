#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;


struct Hash {
    int P = 1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];
    Hash(string& s) {
        MOD[0] = 999727999; MOD[1] = 1070777777;
        PI[0] = 325255434; PI[1] = 10018302;
        forn(k, 2) h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
        forn(k, 2) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            forsn(i, 1, s.size() + 1) {
                h[k][i] = (h[k][i - 1] + p * s[i - 1])%MOD[k];
                pi[k][i] = (1LL * pi[k][i - 1] * PI[k])%MOD[k];
                p = (p * P)%MOD[k];
            }
        }
    }

    ll get(int s, int e) {
        e++;
        ll h0 = (h[0][e] - h[0][s] + MOD[0])%MOD[0];
        h0 = (1LL * h0 * pi[0][s])%MOD[0];
        ll h1 = (h[1][e] - h[1][s] + MOD[1])%MOD[1];
        h1 = (1LL * h1 * pi[1][s])%MOD[1];
        return (h0<<32)|h1;
    }
};

int main() {
    int n; cin>>n;
    set<ll> s;
    forn(i, n) {
        string t; cin>>t;
        Hash h(t);
        s.insert(h.get(0, t.size() - 1));
    }

    // for(auto v : s) cout<<v<<" "; cout<<endl;

    int q; cin>>q;
    while(q--) {
        string t; cin>>t;
        Hash h(t);
        if(s.count(h.get(0, t.size() - 1))) {
            cout<<1<<endl;
            // continue;
        } else {
            int found = 0;
            forn(i, t.size()) {
                if(s.count(h.get(0, i)) and s.count(h.get(i + 1, t.size() - 1))) {
                    found = 2;
                    break;
                }
            }

            cout<<found<<endl;
        }
        
    }
}