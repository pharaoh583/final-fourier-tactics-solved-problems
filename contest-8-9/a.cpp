#include<iostream>
#include<vector>
#define vi vector<int>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)

using namespace std;

vi z_function(string& s) {
    int l = 0, r = 0, n = s.size();
    vi z(n, 0);
    forsn(i, 1, n) {
        if(i<=r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve(int n) {
    string ne; cin>>ne;
    string h; cin>>h;
    string r = ne + "$"+ h;
    vi z = z_function(r);
    forsn(i, n + 1, r.size()) {
        if(z[i] == n) cout<<i - n - 1<<endl;
    }
    cout<<endl;
}

int main() {
    int n;
    while(cin>>n) solve(n);
}