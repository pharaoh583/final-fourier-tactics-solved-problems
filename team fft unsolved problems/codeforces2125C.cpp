#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
using namespace std;

ll getAns(ll r) {
    ll badP[4] = {2, 3, 5, 7};
    ll res = 0;

    forn(mask, (1<<4)) {
        ll prod = 1;
        ll cont = 0;
        forn(j, 4) {
            if((mask & (1<<j)) != 0) {
                prod *= badP[j];
                cont++;
            }
        }

        // cout<<r/prod<<" "<<prod<<endl;

        if(cont%2 == 0) res += r/prod;
        else res -= r/prod;
    }
    // cout<<r<<" "<<res<<endl;
    return res;
}

void solve() {
    ll l, r; cin>>l>>r;
    cout<<getAns(r) - getAns(l - 1)<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
}