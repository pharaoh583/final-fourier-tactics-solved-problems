#include<iostream>
#include<algorithm>
#include<vector>
#define vi vector<int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define pb push_back 
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
    int n; cin>>n;
    vi x, y;

    forn(i, n) {
        int a, b; cin>>a>>b;
        x.pb(a - 1), x.pb(a + 1);
        y.pb(b - 1), y.pb(b + 1);
    }

    sort(all(x));
    sort(all(y));
    int mini = x.back() - x[0] + y.back() - y[0];
    cout<<2 * mini<<endl;
}