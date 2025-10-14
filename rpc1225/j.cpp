#include<iostream>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
int main() {
    int n, d; cin>>n>>d;
    int days[d];
    forn(i, d) days[i] = n;
    forn(i, n) {
        int v; cin>>v;
        forn(j, v) {
            int a, b; cin>>a>>b; a--, b--;
            forsn(k, a, b + 1) {
                days[k]--;
            }
        }
    }
    int cont = 0;
    forn(i, d) {
        if(days[i] >= 3) cont++;
    }
    cout<<cont<<endl;
}