#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
using namespace std;

const int maxn = 21;

int pieceId[6][6];
ii pieceVal[maxn];
int sum[(1<<maxn)];

int p[6][6];
bool vis[6];

bool isValid() {
    fill(vis, vis + 6, false);

    int odd = 0, cc = 0;

    for (int i = 0; i < 6; i++) {
        int deg = 0;
        for (int j = 0; j < 6; j++) {
            if (p[i][j]) deg+=p[i][j];
        }
        if (deg == 0) continue;

        if (deg % 2) {
            odd++;
            if (odd > 2) return false;
        }

        if (!vis[i]) {
            cc++;
            if (cc > 1) return false;
            stack<int> st; st.push(i);
            vis[i] = true;

            while (!st.empty()) {
                int u = st.top(); st.pop();
                for (int v = 0; v < 6; v++) {
                    if (p[u][v] and !vis[v]) {
                        vis[v] = true;
                        st.push(v);
                    }
                }
            }
        }
    }

    return (odd == 0 or odd == 2);
}

void init() {
    int cont = 0;
    forn(i, 6) {
        for(int j = i; j < 6; j++) {
            pieceId[i][j] = cont;
            pieceVal[cont++] = ii(i, j);
        }
    }

    forn(s, (1<<maxn)) {
        fill(&p[0][0], &p[0][0] + 6*6, 0);
        forn(i, maxn) {
            if(s&(1<<i)) {
                p[pieceVal[i].F][pieceVal[i].S]++;
                p[pieceVal[i].S][pieceVal[i].F]++;
            }
        }
        if(isValid()) {
            sum[s] = 1;
        }
    }
    
    // forn(i, 10) cout<<sum[i]<<" "; cout<<endl;

    for (int k = 0; k < maxn; k++) {
        for (int s = 0; s < (1<<maxn); s++) {
            if(s&(1<<k)) sum[s] += sum[s^(1<<k)];
        }
    }
}

void solve() {
    int n; cin>>n;
    int mask = 0;
    forn(i, n) {
        int a, b; cin>>a>>b; a--, b--;
        mask |= (1<<pieceId[a][b]);
    }
    cout<<sum[mask] - 1<<endl;
}

int main() {
    init();
    int t; cin>>t;
    while(t--) {
        solve();
    }
}