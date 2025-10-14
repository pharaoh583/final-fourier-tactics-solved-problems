#include<iostream>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;
int main() {
    ll c, n;
    cin>>c>>n;
    if(c == n) {
        cout<<c<<endl;
    }
    else if(c > n) {
        cout<<"0"<<endl;
    } else {
        cout<<c+1<<endl;
    }
}