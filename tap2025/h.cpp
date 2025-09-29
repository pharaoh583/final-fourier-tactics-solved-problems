#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<numeric>
#include<math.h>
// #include<bits/stdc++.h>
#define vi vector<int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define pb push_back 
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
    int n; cin>>n;    
    set<ll> s;
    ll a[n];
    ll lcms = 1;
    forn(i, n) cin>>a[i], s.insert(a[i]), lcms = lcms*(a[i]/gcd(lcms, a[i]));
    sort(a, a + n);

    if(lcms == 1) {
        cout<<'*'<<endl;
        return 0;
    }

    ll res = 0;
    forn(i, n) {
        if(!s.count(lcms/a[i])) {
            res = lcms/a[i];
            break;
        }
    }
    // cout<<lcms<<endl;
    // cout<<res<<endl;
    if(res == 0) {
        cout<<a[n - 1] * a[1]<<" "<<a[n - 1] * a[1]<<endl;
    } else {
        cout<<lcms<<" "<<res<<endl;
    }

}