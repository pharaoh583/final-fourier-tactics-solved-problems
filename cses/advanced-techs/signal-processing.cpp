//22 mins, est: 30
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
#define all(v) (v).begin(),(v).end()
#define pb push_back
using namespace std;

typedef ll tf;
typedef vector<tf> poly;

const int MAXN = 1048576;

struct CD {
    double r, i;
    CD(double r = 0, double i = 0) : r(r), i(i) {}
    double real() const{return r;}
    void operator/=(const int c) {r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b) {
    return CD(a.r*b.r-a.i*b.i, a.r*b.i + a.i*b.r);
}
CD operator+(const CD& a, const CD& b) {return CD(a.r + b.r, a.i + b.i);}
CD operator-(const CD& a, const CD& b) {return CD(a.r-b.r, a.i-b.i);}
const double pi = acos(-1.0);

CD cp1[MAXN + 9], cp2[MAXN+9];
int R[MAXN + 9];
void dft(CD* a, int n, bool inv) {
    forn(i, n) if(R[i] < i) swap(a[R[i]], a[i]);
    for(int m = 2; m <= n; m*=2){
        double z = 2 * pi/m * (inv?-1:1);
        CD wi = CD(cos(z), sin(z));
        for(int j = 0; j < n; j+= m) {
            CD w(1);
            for(int k = j, k2 = j + m/2; k2 < j + m; k++, k2++) {
                CD u = a[k]; CD v=a[k2] * w; a[k] = u + v; a[k2] = u - v; w = w * wi;
            }
        }
    }
    if(inv) forn(i, n) a[i]/=n;
}
poly mult(poly& p1, poly& p2) {
    int n=p1.size() + p2.size() + 1;
    int m = 1, cnt = 0;
    while(m <= n) m += m, cnt++;
    forn(i, m) {R[i] = 0; forn(j, cnt)R[i] = (R[i]<<1)|((i>>j)&1);}
    forn(i, m) cp1[i] = 0, cp2[i] = 0;
    forn(i, p1.size()) cp1[i] = p1[i];
    forn(i, p2.size()) cp2[i] = p2[i];
    dft(cp1, m, false); dft(cp2, m, false);
    forn(i, m) cp1[i] = cp1[i] * cp2[i];
    dft(cp1, m, true);
    poly res;
    n -= 2;
    forn(i, n) res.pb((tf) floor(cp1[i].real() + 0.5));
    return res;
}

int main() {
    int n, m; cin>>n>>m;
    poly a(n), b(m);
    forn(i, n) {
        cin>>a[i];
    }  
    forn(i, m) cin>>b[i];

    reverse(all(b));
    poly res = mult(a, b);
    forn(i, res.size()) {
        cout<<res[i]<<" ";
    } cout<<endl;
}