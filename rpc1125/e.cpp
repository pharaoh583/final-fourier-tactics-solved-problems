#include<bits/stdc++.h>
#include <iomanip>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define S second
#define F first
using namespace std;

const long double EPS = 1e-8;
const long double DINF = numeric_limits<double>::max();

long double abso(long double x){
    return x>0? x : -x;
}

struct pt {
    long double x, y;
    pt(long double x, long double y):x(x), y(y) {}
    pt() {}
    long double norm2() {return *this**this;}
    long double norm() {return sqrt(norm2());}
    bool operator==(pt p) {return abs(x - p.x) <= EPS and abs(y-p.y) <= EPS;}
    pt operator+(pt p) {return pt(x + p.x, y + p.y);}
    pt operator-(pt p) {return pt(x - p.x, y - p.y);}
    pt operator*(long double t) {return pt(x*t, y*t);}
    pt operator/(long double t) {return pt(x/t, y/t);}
    long double operator*(pt p) {
        return x * p.x+ y*p.y;
    }
    long double operator%(pt p) {
        return x*p.y - y *p.x;
    }
    pt unit() {return *this/norm();}
    double angle(pt p) {
        return acos(*this*p/(norm() * p.norm()));
    }
};

int sgn2(long double x){return x < 0 ? -1 : 1;}
struct ln{
    pt p, pq;
    ln(pt p, pt q) : p(p), pq(q - p) {}
    ln(long double x, long double y){
        p = pt(0, y);
        pq = pt(1, 0);
    }

    ln() {}
    bool has(pt r) {
        return dist(r) <= EPS;
    }
    bool seghas(pt r) {return has(r) and (r - p) * (r - (p + pq)) <= EPS;}
    bool operator/(ln l) {return abs(pq.unit()%l.pq.unit())<=EPS;}
    bool operator==(ln l) {return *this/l and has(l.p);}
    pt operator^(ln l) {
        if(*this/l) return pt(DINF, DINF);
        pt r = l.pq * ((p - l.p)%pq)/(l.pq%pq) + l.p;
        return r;
    }
    long double angle(ln l) {return pq.angle(l.pq);}
    int side(pt r) {
        return has(r)?0:sgn2(pq%(r - p));
    }
    pt proj(pt r) {return p + pq * ((r - p)*pq/pq.norm2());}
    long double dist(pt r) {return (r - proj(r)).norm();}
};


bool possible(vector<pt> outer, long double h, long double w){



    long double cosa = abso((outer[3]-outer[2]) * pt(1, 0))/(outer[3]-outer[2]).norm();
    long double sina = sqrt(1 - cosa*cosa);
    long double l = (outer[0] - outer[3]).norm();

    long double x2 = l - h*cosa;
    long double x1 = outer[3].x - x2*sina;
    long double y1 = x2*cosa;
    long double y2 = y1 + h;

    ln r1 = ln(outer[1], outer[2]);
    ln r2 = ln(outer[2], outer[3]);

    double w1 = min((r1^ln(0.0, y1)).x, (r2^ln(0.0, y1)).x) - x1;
    double w2 = min((r1^ln(0.0, y2)).x, (r2^ln(0.0, y2)).x) - x1;

    return w1 >= w - EPS and w2 >= w - EPS;
}

int main() {
    vector<pt> outer(4);
    forn(i, 4){
        long double x, y; cin >> x >> y;
        outer[i] = pt(x, y);
    }
    long double h, w; cin >> w >> h;

    if(abso((outer[0]-outer[1])*pt(1, 0)) < EPS){
        long double outh = (outer[0]-outer[1]).norm();
        long double outw = (outer[1]-outer[2]).norm();
        // cout<<outh<<" "<<outw<<endl;
        
        long double maxi = 0;
        long double h1 = (outw/w)*h;
        if(h1 <= outh + EPS) maxi = outw*h1;
        
        long double w2 = (outh/h)*w;
        if(w2 < outw + EPS) maxi = max(maxi, w2*outh);

        cout << setprecision(6) << fixed<< maxi << endl;
        return 0;
    }
    else{
        vector<pt> outer_aux(4);
        vector<pt> outer_rot(4);
        forn(i, 4){
            outer_aux[i] = outer[(i+1)%4];
        }
        forn(i, 4){
            outer_rot[i] = pt(-outer_aux[(i+3)%4].y, outer_aux[(i+3)%4].x);
        }

        // forn(i, 4){
        //     cout << outer_aux[i].x << ' ' << outer_aux[i].y  << endl;
        // } cout << endl;

        long double l = 0, r = 1e9;
        long double resh = 0, resw = 0;
        while(abso(r - l) > EPS){
            long double mh = (l + r)/2;
            long double mw = (mh/h)*w;
            if(possible(outer_aux, mh, mw)){
                l = mh;
                resh = mh;
                resw = mw;
            }
            else{
                r = mh;
            }
        }
        cout <<  setprecision(6) << fixed << resh * resw << endl;
        return 0;
    }
}