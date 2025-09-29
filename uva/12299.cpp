#include<iostream>
#include<vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define pb push_back

using namespace std;
#define INF (1e7 + 10)
#define NEUT INF

typedef int T;
T op(T a, T b) { return min(a, b);}

struct STree {
    vector<T> st; int n;
    STree(int n) : st(4 * n + 5, NEUT), n(n) {}
    void init(int p, int l, int r, vector<T>& a) {
        if(l == r) {st[p] = a[l]; return;}
        int m = (l + r)/2;
        init(p<<1, l, m, a); init(p<<1|1, m + 1, r, a);
        st[p] = op(st[p<<1], st[p<<1|1]);
    }

    void upd(int p, int l, int r, int pos, T val) {
        if(l == r) {st[p] = val; return;}
        int m = (l + r)/2;
        if(pos <= m) upd(p<<1, l, m, pos, val);
        else upd(p<<1|1, m + 1, r, pos, val);
        st[p] = op(st[p<<1], st[p<<1|1]);
    }
    T query(int p, int l, int r, int a, int b) {
        if(l > b or r < a) return NEUT;
        if(a <= l and r <= b) return st[p];
        int m = (l + r)/2;
        return op(query(p<<1, l, m, a, b), query(p<<1|1, m + 1, r, a, b));
    }

    void init(vector<T>& a) {init(1, 0, n - 1, a);}
    void upd(int p, T val) {upd(1, 0, n - 1, p, val);}
    T query(int a, int b) {return query(1, 0, n - 1, a, b);}
};

pair<int, vector<int> > parseQuery(string a) {
    int num = 0;
    vi v; 
    forn(i, a.size()) {
        if(isdigit(a[i])) {
            num = num * 10 + (a[i] - '0');
        } else if(num != 0){
            v.pb(num); num = 0;
        }
    }
    return make_pair((a[0] == 'q') ? 0 : 1, v);
}

int main() {
    FastIO;
    int n, q; cin>>n>>q;
    vi a(n);
    forn(i, n) cin>>a[i];

    STree st(n);
    st.init(a);

    while(q--) {
        string s; cin>>s;
        pair<int, vector<int> > p = parseQuery(s);
        vi v = p.second;
        if(p.first == 0) {
            cout<<st.query(v[0] - 1, v[1] - 1)<<endl;
        } else {
            // forn(i, v.size()) cout<<v[i]<<" "; cout<<endl;
            forn(i, v.size() - 1) {
                swap(a[v[i] - 1], a[v[(i + 1)] - 1]);
                st.upd(v[i] - 1, a[v[i] - 1]);
            }
            st.upd(v.back() - 1, a[v.back() - 1]);

            // forsn(i, 1, 4 * n) {
            //     cout<<st.st[i]<<" ";
            // } cout<<endl;
        }
    }
}