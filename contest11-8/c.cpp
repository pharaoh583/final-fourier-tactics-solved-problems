#include <iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

int MOD = 1'000'000;

int dp[1000][1000];

int res[1000];

void init() {
    forn(i, 1000) forn(j, 1000) dp[i][j] = 0, res[i] = 0;

    dp[0][0] = 1;
    for(int j = 1; j < 1000; j++) {
        int sum = 0;
        for(int i = j; i >= 0; i--) {
            if(i - 1 >= 0) sum += dp[i - 1][j - 1], sum%=MOD;
            dp[i][j] = (dp[i][j] + sum)%MOD;

            res[j] = (res[j] + dp[i][j])%MOD;
        }
    }


    forn(i, 5) {
        cout<<res[i]<<" ";
    } cout<<endl;

}

int main() {
    init();
    int n;
    while(cin>>n and n != 0) {
        cout<<res[n - 1]<<endl;
    }
}