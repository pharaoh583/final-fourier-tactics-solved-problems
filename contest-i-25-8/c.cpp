#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
using namespace std;

void solve() {
    int n;
    cin>>n;
    long long aux ;
    long long  a, sol = 0;
    cin>>a;
    aux = a;
    forn(i,n - 1){
        cin>>a;
        if(a < aux){
            sol += aux - a;
        }
        aux = max(aux, a);
    }
    cout<<sol<<endl;
}

int main() {
    // int t; cin>>t;
    int t = 1;
    while(t--) {
        solve();
    }
}