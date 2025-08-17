#include <iostream>
#include <vector>
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL)
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

typedef int T;
T op(T a, T b) {return min(a, b);}

struct Table{
    vector<vector<T>> st;
    Table (vector<T>& v) : st(1, v) {
        int n = v.size();
        for(int j = 1; (1<<j) <= n; j++) {
            st.emplace_back(vector<T>(n));
            for(int i = 0; i + (1<<(j - 1)) < n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1<<(j - 1))]);
            }
        }
    }
    // get [l, r]
    T get(int l, int r) {
        int j = 31-__builtin_clz(r - l + 1);
        return op(st[j][l], st[j][r - (1<<j) + 1]);
    }
};

int main() {
    FastIO;
    int n, q; cin>>n>>q;
    vector<int> a(n);
    forn(i, n) {
        cin>>a[i];
    }
    Table t = Table(a);

    while(q--) {
        int l, r; cin>>l>>r;
        cout<<t.get(l - 1, r - 1)<<'\n';
    }
}