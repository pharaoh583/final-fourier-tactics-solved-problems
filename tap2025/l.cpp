#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define vi vector<ll>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define pb push_back 
#define all(x) (x).begin(),(x).end()
using namespace std;

ll ps[(int)1e5 + 1];
ll sum(int l, int r) { //[l, r]
    if(l == 0) return ps[r];
    return ps[r] - ps[l - 1];
}

int main() {
    int n; ll g; cin>>n>>g;
    ll cost[n];
    ps[0] = 0;
    forn(i, n) cin>>cost[i];
    ps[0] = cost[0];
    forsn(i, 1, n) {
        ps[i] = ps[i - 1] + cost[i];
    }
    vi dp(n, 0LL);
    // forn(i, n) cout<<dp[i]<<" "; cout<<endl;
    int sqr = (sqrt(8 * n + 1) + 1)/2 + 10;
    forsn(i, 1, sqr + 1) {
        vi newDp(n, 0LL);
        forn(j, n) {
            if(j - i >= 0) {
                newDp[j] = max(dp[j], g + dp[j - i] - sum(j - i + 1, j));
                // cout<<sum(j - i + 1, j)<<endl;
            }
            else if(i == j + 1){
                newDp[j] = max(dp[j], g - sum(0, j));
            } else newDp[j] = max(dp[j], 0LL);
        }
        dp = newDp;
        forsn(i, 1, n)dp[i] = max(dp[i], dp[i - 1]);
    }

    ll maxi = 0;
    forn(i, n) maxi = max(maxi, dp[i]);
    cout<<maxi<<endl;    
}