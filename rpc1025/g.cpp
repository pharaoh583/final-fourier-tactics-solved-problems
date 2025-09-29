#include<iostream>
using namespace std;

int main() {
    int a, b, c; cin>>a>>b>>c;

    int t = a * b;
    if (t%12 == 0) cout<<(t/12) * c<<endl;
    else cout<<(t/12 + 1) * c<<endl;
}