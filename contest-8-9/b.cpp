#include<iostream>
#include<vector>
#define vi vector<int>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)

using namespace std;

bool game[101];

void init() {
    game[0] = false;

    forsn(i, 1, 100 + 1) {
        game[i] = false;
        if(i - 5 >= 0) game[i] |= !game[i - 5];
        if(i - 3 >= 0) game[i] |= !game[i - 3];
        if(i - 2 >= 0) game[i] |= !game[i - 2];
    }
}

void solve() {
    int n; cin>>n;
    cout<< ((game[n]) ? "First" : "Second")<<endl;
}

int main() {
    init();
    int t; cin>>t;
    while(t--) solve();
}