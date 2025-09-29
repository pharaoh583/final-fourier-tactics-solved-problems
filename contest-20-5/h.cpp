#include<iostream>
#include<vector>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;

vector<int> getDivi(ll n) {
    vector<int> res;
    for(ll i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            if(i * i == n) res.pb(i);
            else {
                res.pb(i);
                res.pb(n/i);
            }
        }
    }
    return res;
}

int main() {
    int a, b, c; cin>>a>>b>>c;
    vector<int> v = getDivi(c);
    int cont = 0;
    forn(i, v.size()) {
        // cout<<v[i]<<" ";
        if(v[i] >= a and v[i] <= b) cont++;
    }
    // cout<<endl;
    cout<<cont<<endl;
}