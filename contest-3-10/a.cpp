#include<iostream>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int abso(int a) {
    return (a < 0) ? -a : a;
}

void solve() {
    int n, a, b; cin>>n>>a>>b;
    int d = __gcd(a, b);
    int arr[n];
    forn(i, n) {
        cin>>arr[i];
        arr[i] = arr[i]%d;
    }
    sort(arr, arr + n);
    int minDist = d;
    forn(i, n) {
        minDist = min(minDist, abso(arr[(i + 1)%n] - (arr[i] + d)));
    }

    cout<<minDist<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
}