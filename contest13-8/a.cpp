//est:  15, time: 23 problem copying the code
#include <iostream>
#include <vector>
#include <unordered_set>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
using namespace std;

struct Hash {
    int P = 1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];

    Hash(string& s) {
        MOD[0] = 999727999, MOD[1] = 1070777777;

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

        return(h0<<32)|h1;
    }
};

int main() {
    string a; cin>>a;
    string b; cin>>b;
    int k; cin>>k;

    int ps[a.size() + 1];
    ps[0] = 0;
    forn(i, a.size()) {
        ps[i + 1] = ps[i] + ((b[a[i] - 'a'] == '1') ? 0 : 1);
        // cout<<ps[i + 1]<<" ";
    } 
    // cout<<endl;

    Hash h = Hash(a);
    unordered_set<ll> s;

    forn(i, a.size()) {
        forsn(j, i, a.size()) {
            int invalid = ps[j + 1] - ps[i];

            if(invalid <= k) {
                ll curr = h.get(i, j);
                // cout<<i<<" "<<j<<" "<<invalid<<" "<<curr<<endl;
                s.insert(curr);
            }
        }
    }

    cout<<s.size()<<endl;
    return 0;
}