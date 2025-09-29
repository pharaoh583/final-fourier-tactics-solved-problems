#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

int main(){
    ll l, r;
    cin>>l>>r;
    set <ll> num;
    num.insert(l);
    num.insert(l - 1);
    num.insert(r);
    num.insert(r + 1);

    ll sol = 0;
    for(ll n: num){
        sol += n;
    }

    cout<<sol<<endl;

 }