#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> f(n + 1, 0);
    map<int, int> m;
    forn(i, n) {
        int a; cin>>a;
        m[a]++;
    }

    int maxi = 0;

    for(auto [k, v] : m) {
        for(int i = k; i <= n; i += k) {
            f[i] += v;
            maxi = max(maxi, f[i]);
        }
    }

    cout<<maxi<<endl;

}

int main() {
    int t; cin>>t;
    while(t--) solve();
}

