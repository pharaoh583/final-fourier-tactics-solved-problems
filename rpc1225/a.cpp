#include<iostream>
#include<stack>
#include<map>
#include<vector>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
using namespace std;

const int maxi = 1e5 + 1;
int dp[maxi];
int arr[maxi];
int n, l, r; 

int test(int mn, int mx) {
    for(int k = -11; k<= 11; k++) {
        if(mn + 12 * k >= l and mx + 12 * k <= r) return true;
    }
    return false;
}

int main() {
    cin>>n>>l>>r;
    forn(i, n) cin>>arr[i];
    forn(i, n) dp[i] = maxi;
    forn(i, n) {
        int mx = arr[i], mn = arr[i];
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            mx = max(arr[j], mx);
            mn = min(arr[j], mn);
            if(!test(mn, mx)) break;
            
            if(j > 0) {
                dp[i] = max(dp[i], min(dp[j - 1], i - j + 1));
            } else {
                dp[i] = max(dp[i], i + 1);
            }
        }
    }
    // forn(i, n) cout<<dp[i]<<" "; cout<<endl;
    cout<<dp[n - 1]<<endl;
}