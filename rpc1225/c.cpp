#include<iostream>
#include<stack>
#include<map>
#include<vector>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
using namespace std;

vi diq = {-1, -1, 0, 1, 1, 1, 0, -1}, djq = {0, 1, 1, 1, 0, -1, -1, -1};
vi dik = {-2, -1, 1, 2, 2, 1, -1, -2}, djk = {1, 2, 2, 1, -1, -2, -2, -1};
vi dir = {-1, 0, 1, 0}, djr = {0, 1, 0, -1};

int main() {
    int n, p; cin>>n>>p;
    int board[n][n];
    forn(i, n) forn(j, n) {
        board[i][j] = 0;
    }

    forn(k, p) {
        char pname; int r, c; cin>>pname>>r>>c; r--, c--;
        board[r][c]++;
        if(pname == 'Q') {
            forn(d, diq.size()) {
                forsn(i, 1, n + 1) {
                    int nr = r + diq[d] * i;
                    int nc = c + djq[d] * i;
                    if(nr >= n or nr < 0 or nc >= n or nc < 0) break;
                    board[nr][nc]++;
                }   
            }
        }
        else if(pname == 'R') {
            forn(d, dir.size()) {
                forsn(i, 1, n + 1) {
                    int nr = r + dir[d] * i;
                    int nc = c + djr[d] * i;
                    if(nr >= n or nr < 0 or nc >= n or nc < 0) break;
                    board[nr][nc]++;
                }   
            }
        } else {
            forn(d, dik.size()) {
                // forsn(i, 1, n + 1) {
                    int nr = r + dik[d];
                    int nc = c + djk[d];
                    if(nr >= n or nr < 0 or nc >= n or nc < 0) continue;
                    board[nr][nc]++;
                // }   
            }
        }
    }
    int cont = 0;
    forn(i, n) {
        forn(j, n) {
            // cout<<board[i][j]<<" ";
            cont += (board[i][j] != 0);
        } 
        // cout<<endl;
    }
    cout<<cont<<endl;
}