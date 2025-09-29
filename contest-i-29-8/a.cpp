#include<iostream>
#include<set>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

int main() {
    int n; cin>>n;
    multiset<int> values;
    int a[n];
    int sol = 0;
    int l = 0; 
    forn(i, n) cin>>a[i];

    forn(r, n) {
        values.insert(a[r]);
        while(true) {
            int first = *values.begin(), last = *values.rbegin();
            if(last - first <= 1) {
                sol = max(sol, (int)values.size());
                break;
            }
            values.erase(values.find(a[l++]));
        }
    }
    cout<<sol<<endl;
}