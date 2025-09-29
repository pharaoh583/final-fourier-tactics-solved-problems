#include<iostream>
#include<vector>
#define vi vector<ll>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define ll long long
using namespace std;

const ll M = 1e9 + 9;

class Matrix{
public:
    int r, c;
    vector<vi> m;
    Matrix(int rows, int cols) : r(rows), c(cols){m = vector<vi>(r, vi(c, 0));}
    Matrix(int n) : Matrix(n, n) {
        forn(i, r) m[i][i] = 1;
    }
    Matrix(vector<vi> mt) : Matrix(mt.size(), mt[0].size()) { m = mt;}
    Matrix operator*(Matrix b) {
        Matrix res(r, b.c);
        forn(i, r) {
            forn(j, b.c) {
                forn(k, c) {
                    res.m[i][j] = (res.m[i][j] + (m[i][k] * b.m[k][j])%M)%M;
                }
            }
        }
        return res;
    } 
};

Matrix modPow(Matrix a, ll b) {
    if(b == 1) return a;

    Matrix z = modPow(a, b/2);
    if(b&1) return (z * z) * a;
    else return z * z;
}

vi multVectorCol(Matrix a, vi b) {
    vi c(b.size(), 0);
    forn(i, a.r) {
        forn(j, a.c) {
            c[i] = (c[i] + (a.m[i][j] * b[j])%M)%M;
        }
    }
    return c;
}

int main() {
    ll n;
    Matrix m(3);
    m.m[0][0] = 0,m.m[0][1] = 1, m.m[0][2] = 0;
    m.m[1][0] = 0,m.m[1][1] = 0, m.m[1][2] = 1;
    m.m[2][0] = 1,m.m[2][1] = 1, m.m[2][2] = 1;
    vi base = vi({0, 1, 2});

    while(cin>>n and n != 0) {
        n--;
        if(n == 0) {
            cout<<0<<endl; continue;
        }
        Matrix res = modPow(m, n);
        // cout<<res[]
        vi v = multVectorCol(res, base);
        cout<<v[0]<<endl;
    }
}