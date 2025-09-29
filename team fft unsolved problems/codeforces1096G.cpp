//est: 10, real: 65
#include<iostream>
#include<vector>
#include<cmath>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define pb push_back

using namespace std;

typedef ll tf;
typedef vector<tf> poly;
const int MAXN = (1<<21);
const tf MOD = 998244353, RT = 5;
// const double pi = acos(-1, 0);
typedef ll tf;
struct CD {
  tf x;
  CD(tf x) : x(x) {}
  CD() {}
};
ll mulmod(ll a, ll b) {return (a * b)%MOD;}
ll addmod(ll a, ll b) {return (a + b)%MOD;}
ll submod(ll a, ll b) {return (a - b + MOD)%MOD;}
ll pm(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    ll z = pm(a, b/2);
    if(b%2 == 0) {
        return mulmod(z, z);
    }
    else return mulmod(z, mulmod(z, a));
}

CD operator*(const CD& a, const CD& b) {return CD(mulmod(a.x, b.x));}
CD operator+(const CD& a, const CD& b) {return CD(addmod(a.x, b.x));}
CD operator-(const CD& a, const CD& b) {return CD(submod(a.x, b.x));}
vector<tf> rts(MAXN + 9, -1);
CD root(int n, bool inv) {
    tf r = rts[n] < 0?rts[n]=pm(RT, (MOD-1)/n):rts[n];
    return CD(inv?pm(r, MOD-2):r);
}
CD cp1[MAXN + 9], cp2[MAXN + 9];
int R[MAXN + 9];
void dft(CD* a, int n, bool inv) {
    forn(i, n) if(R[i] < i) swap(a[R[i]], a[i]);
    for(int m = 2; m <= n; m *= 2) {
        CD wi = root(m, inv);
        for(int j = 0; j < n; j += m) {
            CD w(1);
            for(int k = j, k2 = j + m/2; k2<j + m; k++, k2++) {
                CD u = a[k]; CD v = a[k2] * w; a[k] = u + v; a[k2] = u - v; w = w * wi;
            }
        }
    }
    if(inv) {
        CD z(pm(n, MOD - 2));
        forsn(i, 0, n) a[i] = a[i] * z;
    }
}

poly multiply(poly& p1, poly& p2) {
    int n = p1.size() + p2.size() + 1;
    int m = 1, cnt = 0;
    while(m <= n) m +=m, cnt++;
    forn(i, m) {R[i] = 0; forn(j, cnt) R[i] = (R[i]<<1)|((i>>j)&1);}
    forn(i, m) cp1[i] = 0, cp2[i] = 0;
    forn(i, p1.size()) cp1[i] = p1[i];
    forn(i, p2.size()) cp2[i] = p2[i];
    dft(cp1, m, false); dft(cp2, m, false);
    forn(i, m) cp1[i] = cp1[i] * cp2[i];
    dft(cp1, m, true);
    poly res;
    n -= 2;
    forn(i, n) res.pb(cp1[i].x);
    return res;
}

poly polyExp(poly a, int b) {
    poly res = poly(1, 1);
    while (b > 0) {
        if (b & 1)
            res = multiply(res, a);
        a = multiply(a, a);
        b >>= 1;
    }
    return res;
}
// poly polyExp(poly& a, int b) {
//     if(b == 0) return poly(1, 1);
//     if(b == 1) return a;
//     poly z = polyExp(a, b/2);
//     if(b%2 == 0) {
//         return multiply(z, z);
//     }
//     else return multiply(z, multiply(z, a));
// }

int main() {
    int n, k; cin>>n>>k;
    poly p(10, 0);
    forn(i, k) {
        int a; cin>>a, p[a]++;
    }
    poly r = polyExp(p, n/2);
    ll res = 0;
    forn(i, r.size()) {
        res = addmod(res, mulmod(r[i], r[i]));
    }
    cout<<res<<endl;
    
}