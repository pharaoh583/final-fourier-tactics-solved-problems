#include<queue>
#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i,s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define all(v) (v).begin(),(v).end()
#define ll long long
#define pb push_back
#define FastIO cin.tie(NULL);ios_base::sync_with_stdio(false)
using namespace std;

int di[] = {-1, -1, 0, 1, 1, 0};
int dj[] = {0, 1, 1, 0, -1, -1};

int main() {
    // cout<<"hello"<<endl;
    // return 0;
    
    // FastIO;
    int n, m;
    while(cin>>n>>m) {
        cout<<"\n";
        if(n == 0 or m == 0) break;
        char g[n][m];
        int vis[n][m];
        vector<ii> start;
        forn(i, n) {
            string s; cin>>s;
            forn(j, m) {
                g[i][j] = s[j];
                vis[i][j] = -1;
                if(g[i][j] == 'I') start.pb(ii(i, j)), vis[i][j] = 0;
            }
        }
        
        forn(k, start.size()) {
            if(g[start[k].first][start[k].second] != 'I') continue;
            queue<ii> q; q.push(start[k]);
            bool valid = true;
            while(!q.empty()) {
                int ci = q.front().first;
                int cj = q.front().second; q.pop();
                forn(l, 6) {
                    int ni = ci + di[l];
                    int nj = cj + dj[l];
                    
                    if(ni >= 0 and ni < n and nj >= 0 and nj < m and (g[ni][nj] == '*' or g[ni][nj] == 'I')) {
                        if(vis[ni][nj] == -1) {
                            vis[ni][nj] = !vis[ci][cj];
                            q.push({ni, nj});
                        }
                        else if(vis[ni][nj] == vis[ci][cj]) {
                            // cout<<ci<<" "<<cj<<endl;
                            // cout<<ni<<" "<<nj<<endl;
                            valid = false;
                        }
                    }
                }
            }
            // cout<<valid<<endl;
            
            q.push(start[k]); 
            while(!q.empty()) {
                int ci = q.front().first;
                int cj = q.front().second; q.pop();
                if(vis[ci][cj] == 3) continue;
                if(valid) g[ci][cj] = (vis[ci][cj]) ? ')' : '(';
                else g[ci][cj] = 'B';
                vis[ci][cj] = 3;
                forn(l, 6) {
                    int ni = ci + di[l];
                    int nj = cj + dj[l];
                    
                    if(ni >= 0 and ni < n and nj >= 0 and nj < m and (g[ni][nj] == '*' or g[ni][nj] == 'I') and vis[ni][nj] != 3) {
                        q.push({ni, nj});
                    }
                }
            }
        }
        
        
        forn(i, n) {
            forn(j, m) {
                if(g[i][j] == '*') cout<<'F';
                else  cout<<g[i][j];
            } cout<<"\n";
        }
        // cout<<endl;
    }
    // cout<<endl;
    return 0;
}