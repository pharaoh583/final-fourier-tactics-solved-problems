#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define S second
#define F first
using namespace std;

int dp[100001][10][2][2][2];
string up;
const int M = 1e4 + 7;
int ways(int i, int prev, bool less, bool twin, bool zero) {
    // cout<<"ways(i: "<<i<<", prev: "<<prev<<", less: "<<less<<", twin: "<<twin<<", zero: "<<zero<<")";
    if(i == up.size()) {
        // cout<<(!twin and !zero)<<endl;
        return (!twin and !zero);
    }
    int &res = dp[i][prev][less][twin][zero];
    if(res != -1) {
        // cout<<" dp "<<res<<endl;
        return res;
    }
    // cout<<endl;
    if(less) {
        int limit = 9;
        if(twin) return res = ways(i + 1, prev, less, false, zero);
        else {
            int sum = 0;
            forn(j, limit + 1) {
                sum = (sum + ways(i + 1, j, less, true^(j==0 and zero), (j == 0 and zero)))%M;
            }
            return res = sum;
        }
    } else {
        int limit = up[i] - '0';
        if(twin) {
            // cout<<"should be twin less that up"<<prev<<" "<<limit<<endl;
            if(prev > limit) return res = 0;
            return res = ways(i + 1, prev, prev < limit, false, zero);
        } else {
            int sum = 0;
            forn(j, limit + 1) {
                sum = (sum + ways(i + 1, j, j < limit, true^(j==0 and zero), (j == 0 and zero)))%M;
            }
            return res = sum;
        }
    }
}
bool checkLeft(string l) {
    if(l.size()%2 == 1) return false;
    for(int i = 0;i < l.size(); i+= 2) {
        if(l[i] != l[i + 1]) return false;
    }
    return true;
}

int main() {
    string l, r; cin>>l>>r;
    forn(i, 100001) forn(j, 10) forn(k, 2) forn(l, 2) forn(m, 2) dp[i][j][k][l][m] = -1;
    up = l;
    int totalL = ways(0, 0, false, false, true) - checkLeft(l);
    // cout<<totalL<<endl;
    forn(i, 100001) forn(j, 10) forn(k, 2) forn(l, 2) forn(m, 2) dp[i][j][k][l][m] = -1;
    up = r;
    int totalR = ways(0, 0, false, false, true);
    // cout<<totalR<<endl;
    cout<<(totalR - totalL + M)%M<<endl;
}