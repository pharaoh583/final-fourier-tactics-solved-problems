#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

int main(){
    int n; cin>>n;
    ll wt = 0;
    ll wp = 0;
    ll w[n];
    forn(i, n) {
        // scanf("%lld", &w[i]);
        cin>>w[i];
        wt += w[i];
    }

    sort(w, w + n);
    reverse(w, w + n);

    double maxi = 0;
    forn(i, n) {
        wp += w[i];
        maxi = max(maxi, double(wp)/double(wt) - double((i + 1))/double(n));
    }

    printf("%.6lf\n", maxi * 100.000000000);

}
