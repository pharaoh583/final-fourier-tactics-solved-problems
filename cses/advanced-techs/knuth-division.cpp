#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
using namespace std;

int main() {
    int n; cin>>n;
    ll arr[n];
    forn(i, n) {
        cin>>arr[i];
    }
    ll pfSum[n];
    forn(i, n) {
        if(i == 0) pfSum[i] = arr[i];
        else pfSum[i] = arr[i] + pfSum[i - 1];
    }

    ll dp[n][n]; int opt[n][n];
    forn(i, n) {
        dp[i][i] = 0;
        forsn(j, i + 1, n) dp[i][j] = LLONG_MAX;
        opt[i][i] = i;
    }

    auto C = [&](int i, int j) {
        if(i == 0) return pfSum[j];
        else return pfSum[j] - pfSum[i - 1];
    };

    for(int i = n - 2; i >= 0; i--) {
        forsn(j, i + 1, n) {
            ll mn = LLONG_MAX;
            ll cost = C(i, j);
            for(int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
                if(mn > (dp[i][k] + dp[k + 1][j] + cost)) {
                    opt[i][j] = k;
                    mn = (dp[i][k] + dp[k + 1][j] + cost);
                }
            }
            dp[i][j] = mn;
        }
    }

    // forn(i, n) {
    //     forsn(j, i, n) cout<<dp[i][j]<<" "; cout<<endl;
    // }
    cout<<dp[0][n - 1]<<endl;
}