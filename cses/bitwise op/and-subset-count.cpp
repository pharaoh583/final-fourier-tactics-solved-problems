#include<iostream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

const int maxn = 200001;

int main() {
    int n; cin>>n;
    int sum[maxn];
    forn(i, maxn) {
        sum[i] = 0;
    }
    forn(i, n) {
        int a; cin>>a;
        sum[a]++;
    }

    for(int k = 0; k < n; k++) {
        for(int s = 0; s < maxn; s++) {
            if(s&(1<k)) sum[s] += sum[s^(1<<k)];
        }
    }

    
}