#include<iostream>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
int main() {
    int p1 = 0, p2 = 0, p3 = 0;
    string r1, r2, r3; cin>>r1>>r2>>r3;
    while(p1 < r1.size() or p2 < r2.size() or p3 < r3.size()) {
        if(p1 == r1.size()) {
            p2++, p3++;
            cout<<1; continue;
        }
        if(p2 == r2.size()) {
            p1++, p3++;
            cout<<2; continue;
        }
        if(p3 == r3.size()) {
            p2++, p1++;
            cout<<3; continue;
        }
        int dat[4]; forn(i, 4) dat[i] = 0;
        dat[r1[p1] - '0']++;
        dat[r2[p2] - '0']++;
        dat[r3[p3] - '0']++;
        if(dat[1] == 2) {
            p2++, p3++;
            cout<<1; continue;
        }
        if(dat[2] == 2) {
            p1++, p3++;
            cout<<2; continue;
        }
        if(dat[3] == 2) {
            p2++, p1++;
            cout<<3; continue;
        }
    }
}