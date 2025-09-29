//est 5; real 35
#include<iostream>
#include<vector>
#include<algorithm>
#define forn(i, n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;

vector<bool> bits(ll n) {
    ll maxi = 0;
    int cont = 0;

    for(ll i = 1; i <= n; i *= 2) {
        if((n&i) != 0) maxi = i;
    }
    
    vector<bool> b;

    for(ll i = 1; i <= n; i *= 2) {
        if((n&i) != 0) b.push_back(1);
        else b.push_back(0); 
    }
    reverse(b.begin(), b.end());
    return b;
}

ll modPow(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;

    ll z = modPow(a, b/2);
    if(b%2 == 0) {
        return z * z;
    }
    else return z * z * a;
}

void solve() {
    ll n; cin>>n;
    vector<bool> b = bits(n);

    int z = 0;
    forn(i, b.size()) z += (b[i] == 0);

    ll even = 0;
    forn(i, b.size()) {
        if(b[i] == 1) {
            even += (modPow(2, z) - 1) * (modPow(2, b.size() - (i + 1) - z)); 
        } else {
            z--;
        }
    }

    cout<<even<<" "<<n + 1 - even<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
}