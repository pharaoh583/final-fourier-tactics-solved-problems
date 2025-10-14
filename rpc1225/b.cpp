#include<iostream>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
int main() {
    ll d, a, b, ra, rb; 
    cin>>d>>a>>b>>ra>>rb;
    ll u = max(a - ra * d, (ll)0);
    ll d2 = (max(a - ra * d, (ll)0) + max(b - rb * d, (ll)0));
    double sol = (double)(u)/(double)(d2) * 100.000000000;
    sol = min(sol, 100.00000000);
    printf("%.7lf\n", sol);
}