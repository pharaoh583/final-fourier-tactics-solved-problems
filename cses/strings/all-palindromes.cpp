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
    string t; cin>>t;
    manacher(t);
    int n = t.size();
    int maxP[n];
    forn(i, n) maxP[i] = 1;
    // maxP[0] = 1;

    for(int i = 1; i < n; i++) {

        if(t[i] == t[i - 1]) maxP[i] = 2;
        if(i >= 2 and t[i] == t[i - 2]) maxP[i] = 3;

        int s = i - maxP[i - 1] - 1;
        // cout<<s<<endl;
        if(s >= 0 and t[s] == t[i]) {
            maxP[i] = max(maxP[i], maxP[i - 1] + 2);
        }
    }

    forn(i, n) {
        maxP[i + d1[i] - 1] = max(maxP[i + d1[i] - 1], 2 * d1[i] - 1);
        maxP[i + d2[i] - 1] = max(maxP[i + d2[i] - 1], 2 * d2[i]);
    }

    forn(i, n) cout<<maxP[i]<<" "; cout<<endl;
}

int main() {
    // int t; cin>>t;
    int t = 1;
    while(t--) {
        solve();
    }
}