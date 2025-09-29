#include<iostream>
#include<vector>
#include<cassert>
#include<tuple>
#include<set>
#include<queue>
#include<algorithm>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define ii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
using namespace std;

const int maxn = 1e6;

const int MAXI = 3001;
vector<long long> prefSum(MAXI);
vector<long long> prefSumProd(MAXI);
ll arr[MAXI];

int n, k;
ll dp[MAXI][MAXI];

void init(){
    prefSum[0] = arr[0];
    prefSumProd[0] = 0;
    forsn(i, 1, n){
        prefSum[i] = prefSum[i - 1] + arr[i];
        prefSumProd[i] = prefSumProd[i - 1] + (arr[i] * i);
    }
    forn(i, n) cout<<prefSum[i]<<" "; cout<<endl;
    forn(i, n) cout<<prefSumProd[i]<<" "; cout<<endl;

    forn(i, MAXI) forn(j, MAXI) dp[i][j] = -1;
}

ll sum_range(int l, int r){
    cout<<l<<" "<<r<<endl;
    ll res = prefSum[r];
    cout<<res<<endl;
    if(l > 0) res-= prefSum[l-1];
    return res;
}

ll sum_prod_range(int l, int r){
    // cout<<l<<" "<<r<<endl;
    ll res = prefSumProd[r];
    // cout<<res<<endl;
    if(l > 0) res-= prefSumProd[l-1];
    return res;
}

ll cost(int l, int r){
    long long count = sum_range(l, r);
    long long offset = l>0? prefSum[l-1]: 0;
    auto it = lower_bound(prefSum.begin()+l, prefSum.begin()+r+1, ((count+1)/2) + offset);

    int m = it - prefSum.begin();
    ll sumr = sum_prod_range(m + 1, r) - m * sum_range(m + 1, r);
    ll suml =  (m * sum_range(l, m)) - sum_prod_range(l, m);
    cout<<"dbg: "<<sumr<<" "<<suml<<endl;

    return sumr + suml;
}

int main() {
    cin >> n >> k;
    forn(i, n) cin >> arr[i];
    init();

    cout<<cost(0, n)<<endl;

    forn(i, n) dp[0][i] = 0;
    for(int h=1; h<=k; h++){
        for(int i=h - 1; i<n; i++){
            if(dp[h-1][i-1] == -1) {
                dp[h][i] = -1;
                continue;
            }

            dp[h][i] = ((h == 0) ? 0:dp[h-1][i-1]) + cost(i, n-1);
        }
    }

    forn(i, k) {
        forn(j, n){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[k][n-1] << endl;
}