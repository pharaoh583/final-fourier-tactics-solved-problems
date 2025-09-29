#include<iostream>
#include<algorithm>
#include<vector>
#define vi vector<int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define pb push_back 
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
    int n, m; cin>>n>>m;

    int gold[n + 1];
    forn(i, n + 1) gold[i] = 0;
    forn(i, m) {
        int x, y; cin>>x>>y;
        vi op1;
        forn(j, n) {
            int op; cin>>op;
            if(op == 1) op1.pb(j);
            else gold[j] += y;
        }

        int c1 = op1.size() + 1;
        if(x/c1 >= y) {
            gold[n] += x/c1;
            forn(j, op1.size()) {
                gold[op1[j]] += x/c1;
            }
        }
        else {
            c1--;
            gold[n] += y;
            forn(j, op1.size()) {
                gold[op1[j]] += x/c1;
            }
        }
    }

    forn(i, n + 1) cout<<gold[i]<<" "; cout<<endl;
}