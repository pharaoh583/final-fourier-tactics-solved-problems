#include<iostream>
#define ll long long
using namespace std;

const ll M = 1e9 + 7;

ll modexp(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    ll z = modexp(a, b/2);
    if(b%2 == 0) return (z * z)%M;
    else return ((z * z)%M * a)%M;
}

int main() {
    int n; cin>>n;
    cout<<modexp(2, n)<<endl;
}