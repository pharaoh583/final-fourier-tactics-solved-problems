#include <bits/stdc++.h>
#include<iomanip>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define pb push_back
using namespace std;

const long double EPS = 1e-9;

struct pt {
    long double x, y;
    pt(long double x, long double y) : x(x), y(y) {}
    pt() {}
    long double norm2() {return *this**this;}
    long double norm() {return sqrt(norm2());}
    bool operator == (pt p) {return abs(x - p.x) <= EPS and abs(y - p.y) <= EPS;}
    pt operator + (pt p) {return pt(x + p.x, y + p.y);}
    pt operator - (pt p) {return pt(x - p.x, y - p.y);}
    pt operator * (long double t) {return pt(x * t, y * t);}
    pt operator / (long double t) {return pt(x / t, y / t);}
    long double operator * (pt p) {return x*p.x + y*p.y;}
};
pt ccw90(1,0);
pt cw90(-1,0);

long double extend(pt u, pt a, pt center, pt b, pt v) {
    long double ca = abs((a - u) * (b - a))/(a - u).norm()/(b - a).norm();
    long double cb = abs((b - v) * (b - a))/(b - v).norm()/(b - a).norm();
    long double r = (b - a).norm()/2;

    long double lenght = (center - a).norm() + (center - b).norm();
    long double x1 = (ca <= EPS) ? r : -r * (1 - 2 * ca * ca);
    long double x2 = (cb <= EPS) ? -r : r * (1 - 2 * cb * cb);

    // cout<<x1<<" "<<x2<<endl;
    if (x2 < x1) return 0;
    if (x1 <= EPS and x2 >= EPS) return (pt(0, r) - pt(-r, 0)).norm() + (pt(0, r) - pt(r, 0)).norm() - lenght;
    if (x2 <= 0) return (pt(x2, sqrt(r * r - x2 * x2)) - pt(-r, 0)).norm() + (pt(x2, sqrt(r * r - x2 * x2)) - pt(r, 0)).norm() - lenght;
    if (x1 >= 0) return (pt(x1, sqrt(r * r - x1 * x1)) - pt(-r, 0)).norm() + (pt(x1, sqrt(r * r - x1 * x1)) - pt(r, 0)).norm() - lenght;
    return 0;
}

int main() {
    int n; cin>>n;
    vector<pt> v;

    forn(i, n) {
        long double x, y; cin>>x>>y;
        v.pb(pt(x, y));
    }
    reverse(all(v));
    long double maxi = 0;
    forn(i, n) {
        long double val = extend(v[i], v[(i + 1)%n], v[(i + 2)%n], v[(i + 3)%n], v[(i + 4)%n]);
        // cout<<val<<endl;
        maxi = max(maxi, val);
    }
    cout<<setprecision(10)  << fixed << maxi<<endl;
}