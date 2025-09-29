#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define S second
#define F first
using namespace std;

double dist(ii a, ii b) {
    return sqrt((a.F - b.F)*(a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

double m[50][50];
double cp[50][50];

int main() {
    int n, k, m; cin>>n>>m>>k;

    vector<ii> p[n];
    forn(i, n) {
        cin>>p[i].F>>p[i].S;
    }

    forn(i, n) forn(j, n) m[i][j] = 1e10;
    forn(i, n) {
        double d = dist(p[i], p[(i + 1)%n]);
        m[i][(i + 1)%n] = d;
        m[(i + 1)%n][i] = d;
    }

    pair<ii, int> newEdges[m];
    forn(i, m) {
        cin>>newEdges[i].F.F>>newEdges[i].F.S>>newEdges[i].S;
        newEdges[i].F.F--; newEdges[i].F.S--;
    }

    int mini = INT_MAX;
    forn(mask, (1<<n)) {
        forn(i, n) forn(j, n) {
            cp[i][j] = m[i][j];
        }
        forn(i, n) {
            
        }
    }  

}