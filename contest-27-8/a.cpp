#include<iostream>
#include<vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
using namespace std;

vi z_function(string& s) {
    int l = 0, r = 0, n = s.size();
    vi z(n, 0);
    forsn(i, 1, n) {
        if(i <= r) z[i] = min(r-i+1, z[i - l]);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

vi kmppre(string& t) {
    vi r(t.size() + 1); r[0] = -1;
    int j = -1;
    forn(i, t.size()) {
        while(j >= 0 and t[i] != t[j]) j = r[j];
        r[i + 1] = ++j;
    }
    return r;
}

int main() {
    string s; cin>>s;
    vi z = z_function(s);
    vi p = kmppre(s);

    forn(i, z.size()) {
        cout<<z[i]<<" ";
    } cout<<endl;
    forsn(i, 1, p.size()) {
        cout<<p[i]<<" ";
    } cout<<endl;
}