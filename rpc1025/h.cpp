#include<iostream>
using namespace std;

int main() {
    int a, b, c; cin>>a>>b>>c;
    int d, e, f; cin>>d>>e>>f;

    int t1 = a + b * 2 + c * 3;
    int t2 = d + e * 2 + f * 3;

    if(t1 == t2) cout<<0<<endl;
    else if(t1 > t2) cout<<1<<endl;
    else cout<<2<<endl;
}