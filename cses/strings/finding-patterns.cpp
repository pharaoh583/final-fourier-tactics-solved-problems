#include <iostream>
#include <map>
#include <vector>

#define FastIO cin.tie(NULL); ios_base::sync_with_stdio(false)
#define forn(i,n) for(int i=0; i<int(n); i++)
#define forsn(i,s,n) for(int i=int(s); i<int(n); i++)
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define i4 pair<ii, ii>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define el '\n'
using namespace std;

struct vertex {
    map<char, int> next, go;
    int p, link;
    char pch;
    vector<int> leaf;
    vertex(int p = -1, char pch = -1) : p(p), pch(pch), link(-1) {}
};
vector<vertex> t;
void aho_init() {
    t.clear();
    t.pb(vertex());
}

void add_string(string s, int id) {
    int v = 0;
    for(char c:s) {
        if(!t[v].next.count(c)) {
            t[v].next[c] = t.size();
            t.pb(vertex(v, c));
        }
        v = t[v].next[c];
    }
    t[v].leaf.pb(id);
}

int go(int v, char c);

int get_link(int v) {
    if(t[v].link < 0) {
        if(t[v].link < 0) {
            if(!v or !t[v].p) t[v].link = 0;
            else t[v].link = go(get_link(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}

int go(int v, char c) {
    if(!t[v].go.count(c)) {
        if(!t[v].go.count(c)) t[v].go[c] = t[v].next[c];
        else t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
    }
    return t[v].go[c];
}

vector<bool> r;
bool vis[1<<20];

void proc(int x) {
    if(x == -1 || vis[x]) return;
    vis[x] = true;
    forn(i, t[x].leaf.size()) r[t[x].leaf[i]] = true;
    proc(t[x].link);
}

void solve() {
    aho_init();
    string text;
    cin>>text;
    int q; cin>>q;
    r = vector<bool>(q, false);
    forn(k, q){
        string a; cin>>a;
        add_string(a, k);
    }
    int kk = 0;
    forn(i, text.size()) {
        kk = go(kk, text[i]);
        proc(kk);
    }
    forn(i, q) {
        if(r[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main() {
    // int t; cin >> t;
    int t = 1;
    while(t--) solve();
    return 0;
}