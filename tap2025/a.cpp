#include<iostream>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    string t; cin>>t;

    string base = "TAP";
    int idx = 0;
    forn(i, t.size()) {
        if(t[i] == base[idx]) {
            idx++;
            if(idx == 3) {
                cout<<"S"<<endl;
                return 0;
            }
        }
    }
    cout<<"N"<<endl;
}