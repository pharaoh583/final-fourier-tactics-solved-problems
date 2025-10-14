#include<iostream>
#include<stack>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

int di[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
char dir[] = {124, 47, 45, 92, 124, 47, 45, 92};

int main() {
    char draw[50][50] = {};
    int n, m; cin>>n>>m;
    forn(i, n) forn(j, m) {
        cin>>draw[i][j];
    }
    // forn(i, n) {
    //     forn(j, m) cout<<draw[i][j];
    //     cout<<endl;
    // }
    int maxi = 0;
    forn(i, n) forn(j, m) {
        if(draw[i][j] == '+') {
            forsn(k, 1, min(n, m) + 1) {
                bool f = true;
                forn(l, 8) {
                    int ni = i + di[l] * k;
                    int nj = j + dj[l] * k;
                    if(ni < 0 or ni >= n or nj < 0 or nj >= m) {
                        f = false;
                        break;
                    }
                    if(draw[ni][nj] != dir[l]) {
                        f = false; break;
                    }
                }
                if(f) maxi = max(maxi, k);
                    else break;
            }
        }
    }
    cout<<maxi<<endl;
}

/*
5 6
\.\|/.
---+--
/./|\.
./.|.\
/..|..

7 7
\.|./..
.\|/...
--+--..
./|\...
/.|.\|/
....-+-
..../|\

7 7
\|/|\|/
-+-|-+-
/|\|/|\
---+---
\|/|\|/
-+-|-+-
/|\|/|\
*/