#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define S second
#define F first
using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int main() {
    int r, c; cin>>r>>c;
    string m[r];
    int vis[r][c];
    int mini[r][c];
    queue<ii> q;
    forn(i, r) {
        cin>>m[i];
        forn(j, c) {
            // cout<<m[i][j]<<" ";
            if(m[i][j] == 'W') {
                // cout<<i<<" "<<j<<endl;
                vis[i][j] = 0;
                q.push(ii(i, j));
            } else {
                vis[i][j] = -1;
            }            
            mini[i][j] = INT_MIN;
        }
        // cout<<endl;
    }

    // forn(i, r) {
    //     forn(j, c) cout<<vis[i][j]<<" ";
    //     cout<<endl;
    // }

    while(!q.empty()) {
        auto [ci, cj] = q.front(); q.pop();
        forn(k, 4) {
            int ni = ci + di[k], nj = cj + dj[k];
            if(ni >= 0 and ni < r and nj >= 0 and nj < c and vis[ni][nj] == -1) {
                vis[ni][nj] = vis[ci][cj] + 1;
                q.push(ii(ni, nj));
            }
        }
    }

    // forn(i, r) {
    //     forn(j, c) cout<<vis[i][j]<<" ";
    //     cout<<endl;
    // }

    priority_queue<pair<int, ii>> pq;
    pq.push(mp(vis[0][0], ii(0, 0)));
    mini[0][0] = vis[0][0];

    while(!pq.empty()) {
        int cost = pq.top().F;
        auto [ci, cj] = pq.top().S; pq.pop();

        if(mini[ci][cj] > cost) continue;

        forn(k, 4) {
            int ni = ci + di[k], nj = cj + dj[k];
            if(ni >= 0 and ni < r and nj >= 0 and nj < c and min(cost, vis[ni][nj]) > mini[ni][nj]) {
                mini[ni][nj] = min(cost, vis[ni][nj]);
                pq.push(mp(mini[ni][nj], ii(ni, nj)));
            }
        }
    }

    // forn(i, r) {
    //     forn(j, c) cout<<mini[i][j]<<" ";
    //     cout<<endl;
    // }

    cout<<mini[r - 1][c - 1]<<endl;
    
}