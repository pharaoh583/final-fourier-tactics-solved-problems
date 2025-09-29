#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ii pair<int, int> 
using namespace std;


const int MAXI = 1e7 + 1;

vector<int> primes;
int sieve[MAXI];
int curr_primes[30]; int n_p = 0;

void init(){
    sieve[0] = sieve[1] = 1;

    forn(i, MAXI){
        if(sieve[i] == 0){
            sieve[i] = i;
            primes.pb(i);
        }

        for(int j = 0; j < primes.size() and 1LL*i*primes[j] < MAXI; j++){
            sieve[i*primes[j]] = primes[j];
            if(primes[j] == sieve[i]) break;
        }
    }
}

long long count_coprimes(int x, int r){
    n_p = 0;
    int curr_p = sieve[x];
    while(x > 1){
        curr_primes[n_p++] = curr_p;
        while(sieve[x] == curr_p) x /= curr_p;
        curr_p = sieve[x];
    }

    // for(auto e: curr_primes){
    //     cout << e << " ";
    // }

    long long res = 0;
    for(int i=1; i<(1<<n_p); i++){
        int prod = 1;
        for(int j=0; j<n_p; j++){
            if((i>>j)&1) prod *= curr_primes[j];
        }
        if(__builtin_popcount(i)%2 == 1) res += r/prod;
        else res -= r/prod;
    }

    return r - res;
}

void solve() {
    int a, b, c, d; 
    cin >> a >> b >> c >> d;
    long long res = 0;
    for(int i=a; i<=b; i++){
        res += count_coprimes(i, d) - count_coprimes(i, c-1);
    }

    cout << res << endl;
}

int main() {
    // int t; cin>>t;

    init();
    int t = 1;
    while(t--) solve();
}

