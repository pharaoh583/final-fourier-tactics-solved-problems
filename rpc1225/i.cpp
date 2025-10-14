#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
#define pb push_back
#define mp make_pair
using namespace std;

int abso(int a) { return (a < 0)? -a : a;}
int getDist(int a, int b) {
    return abso(a - b);
}

int main(){
    int n, m, s, p, q; cin>>n>>m>>s>>p>>q; s--;
    int totalPages = n/m + (n%m != 0);

    bitset<1000> pages[totalPages];
    bitset<1000> want[totalPages];
    int changes[totalPages];
    forn(i, n) changes[i] = 0;
    forn(i, p) {
        int mrk; cin>>mrk; mrk--;
        int page = mrk/m;
        int item = mrk%m;
        pages[page][item] = true;
    }
    forn(i, q) {
        int mrk; cin>>mrk; mrk--;
        int page = mrk/m;
        int item = mrk%m;

        want[page][item] = true;
    }

    forn(i, totalPages) {
        changes[i] = (pages[i]^want[i]).count();
        // cout<<(pages[i]^want[i]).count()<<" ";
        pages[i].set();
        changes[i] = min((int)(pages[i]^want[i]).count() + 1 - (1000 - m), changes[i]);
        // cout<<(int)(pages[i]^want[i]).count() + 1 - (1000 - m)<<" ";
        pages[i].reset();
        changes[i] = min((int)(pages[i]^want[i]).count() + 1, changes[i]);
        // cout<<(int)(pages[i]^want[i]).count() + 1<<endl;
    }

    int l = totalPages - 1, r = 0;
    forn(i, totalPages) {
        if(changes[i] != 0) {
            l = min(l, i);
            r = max(r, i);
        }
        // cout<<changes[i]<<" ";
    }
    // cout<<endl;

    int total = 0;
    if(l <= s and s <= r) {
        total += 2 * min(s - l, r - s) + max(s - l, r - s);
    } else if(s <= l) {
        total = r - s;
    } else {
        total = s - l;
    }
    // cout<<total<<endl;
    
    forn(i, totalPages)total += changes[i];
    cout<<total<<endl;
}