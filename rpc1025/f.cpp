#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define pb push_back
using namespace std;

vector<int> getDivi(int n) {
    vector<int> d;
    for(int i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            if(i * i == n) d.pb(i);
            else d.pb(n/i), d.pb(i);
        }
    }
    return d;
}

int gcd(int a, int b) {
    while(b) {
        int t = a%b; a = b; b = t;
    } return a;
}

int main() {
    int h, w; cin>>h>>w;
    string m[h]; vi v;
    int cont = 0;
    forn(i, h) {
        cin>>m[i];
        int s = 0;
        forn(j, w) {
            if(m[i][j] == '.') {
                if(s != 0) v.pb(s);
                s = 0;
            } else s++, cont++;
        }
        if(s != 0) v.pb(s);
    }

    forn(i, w) {
        int s = 0;
        forn(j, h) {
            if(m[j][i] == '.') {
                if(s != 0) v.pb(s);
                s = 0;
            } else s++;
        }
        if(s != 0) v.pb(s);
    }

    int res = v[0];
    forn(i, v.size()) res = gcd(res, v[i]);

    vi d = getDivi(res);
    sort(all(d));

    bool vis[h][w];
    reverse(all(d));
    // forn(i, d.size()) cout<<d[i]<<" "; cout<<endl;

    forn(k, d.size()) {
        memset(vis, false, sizeof(bool) * h * w);
        int marked = 0;
        bool valid = true;
        forn(i, h) {
            forn(j, w) {
                if(!vis[i][j] and m[i][j] == '#' and valid) {
                    forn(l, d[k]) forn(p, d[k]) {
                        if(m[i + l][j + p] != '#') {
                            valid = false;
                            break;
                            break;
                        }
                        vis[i + l][j + p] = true;
                        marked++;
                    }
                }
                if(!valid) break;
            }
            if(!valid) break;
        }

        if(marked == cont) {
            cout<<d[k]<<endl;
            return 0;
        }
    }
}