#include<iostream>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int a, b, c; cin>>a>>b>>c;
    if((b - a)%c == 0) cout<<"S"<<endl;
    else cout<<"N"<<endl;
}