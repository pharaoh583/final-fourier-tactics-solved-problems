#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;

int main() {
    int n; cin>>n;
    ll arr[n];
    ll sum = 0;
    forn(i, n) {
        cin>>arr[i]; sum += arr[i];
    }

    sort(arr, arr + n);
    reverse(arr, arr + n);
    if(arr[0] > sum - arr[0]) cout<<2 * arr[0]<<endl;
    else cout<<sum<<endl;
}