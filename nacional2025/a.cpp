#include<iostream>
#define ii pair<int, int>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define F first
#define S second
using namespace std;

ii getValidPiece(ii a) {
    if(a.F > a.S) swap(a.F, a.S);
    return a;
}

void solve() {
    int n; cin>>n;
    int prev[6][6], curr[6][6];
    forn(i, 6) forn(j, 6) prev[i][j] = 0;

    ii pieces[n];
    forn(i, n) cin>>pieces[i].F>>pieces[i].S, pieces[i].F--, pieces[i].S--;

    forn(i, n) {
        forn(i, 6) forn(j, 6) curr[i][j] = 0; //first restart curr
        curr[pieces[i].F][pieces[i].S]++;
        forn(j, 6) { 
            //matching first
            ii prevPiece = getValidPiece(ii(j, pieces[i].F));
            ii currPiece = getValidPiece(ii(j, pieces[i].S));
            curr[currPiece.F][currPiece.S] += prev[prevPiece.F][prevPiece.S];
            if(pieces[i].F == pieces[i].S) continue;
            //matching second
            prevPiece = getValidPiece(ii(j, pieces[i].S));
            currPiece = getValidPiece(ii(j, pieces[i].F));
            curr[currPiece.F][currPiece.S] += prev[prevPiece.F][prevPiece.S];
        }
        forn(j, 6) {
            forn(k, 6) {
                prev[j][k] += curr[j][k]; 
            } 
        }
    }

    int sum = 0;
    forn(i, 6) forn(j, 6) sum += prev[i][j];
    cout<<sum<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
}