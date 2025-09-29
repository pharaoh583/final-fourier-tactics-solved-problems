#include<iostream>
#include<vector>
#include<cassert>
#include<tuple>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
#define ii pair<ll, ll>
#define pb push_back
using namespace std;
ll dp[101][101];
const ll M = 1e6;
void init() {
    forn(i, 101) {
        forn(j, 101) {
            if(j == 0 and i != 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = 1;
            else {
                ll sum = 0;
                forn(k, i + 1) {
                    sum = (dp[k][j - 1] + sum)%M;;
                }
                dp[i][j] = sum%M;
            }
        }
    }
}

int main() {
    init();
    int n, k;
    while(cin>>n>>k and n !=0 and k != 0) {
        cout<<dp[n][k]<<endl;
    }
}