#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

int main() {
    int n; cin>>n;
    int odd = 0;
    forn(i, n) {
        int a; cin>>a;
        if(a%2 == 1) odd++;
    }
    cout<<odd<<endl;
}