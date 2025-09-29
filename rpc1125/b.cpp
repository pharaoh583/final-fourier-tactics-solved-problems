#include<iostream>
#include<map>
#include<set>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

int main() {
    string t; cin>>t;
    int dat[10];
    forn(i, 10) dat[i] = 0;
    set<int> s;
    forn(i, t.size()) {
        dat[t[i] - '0']++;
    }

    forn(i, 10) {
        if(dat[i] != 0)s.insert(dat[i]);
    }

    if(s.size() != 2 or *s.begin() != 2 or *s.rbegin() != 3) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}