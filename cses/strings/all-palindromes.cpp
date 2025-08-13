#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

int d1[200000], d2[200000];

void manacher(string& s) {
    int l = 0, r = -1, n = s.size();
    forn(i, n) {
        int k = i > r ? 1 : min(d1[l + r - i], r - i);
        while(i + k < n and i - k >= 0 and s[i + k] == s[i - k]) k++;
        d1[i]=k--;
        if(i + k > r) l = i - k, r = i + k;
    }

    l = 0, r = -1;
    forn(i, n) {
        int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1); k++;
        while(i + k < n and i - k >= 0 and s[i + k - 1] == s[i - k]) k++;
        d2[i] = --k;
        if(i + k - 1 > r) l = i - k, r = i + k - 1;
    }
}

void solve() {
    string s; cin>>s;
    manacher(s);
    int res[s.size()]; forn(i, s.size()) res[i] = 1;
    forn(i, s.size()) {
        res[i + d1[i] - 1] = max(res[i + d1[i] - 1], 2 * d1[i] - 1);
        res[i + d2[i] - 1] = max(res[i + d2[i] - 1], 2 * d2[i]);
    }

    forn(i, s.size()) cout<<res[i]<<" "; cout<<endl;
}

int main() {
    // int t; cin>>t;
    int t = 1;
    while(t--) {
        solve();
    }
}