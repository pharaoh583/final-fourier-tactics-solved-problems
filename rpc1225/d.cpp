#include<iostream>
#include<map>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;
int main() {
    string t; cin>>t;
    map<char, int> m;
    forn(i, t.size()) {
        m[t[i]]++;
    }

    int odd = 0, even = 0;
    for(auto [k, v] : m) {
        if(v%2 == 0) even++;
        else odd++;
    }

    if(odd <= 1) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}