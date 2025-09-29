#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

const int MAXI = 36;

long long M, n;
long long arr[MAXI];

vector<long long> subsetsum(int l, int r){
    vector<long long> res;
    int length = r-l+1;

    for(int i=0; i < (1<<length); i++){
        long long sum_aux = 0;
        forn(j, length){
            if((i >> j) & 1){
                sum_aux = (sum_aux + arr[l+j])% M;
            }
        }
        res.push_back(sum_aux);
    }
    return res;
}

int main() {
    cin >> n >> M;
    forn(i, n) cin >> arr[i];

    vector<long long> left = subsetsum(0, n/2);
    vector<long long> right = subsetsum((n/2)+1, n-1);

    sort(all(right));
    long long res = 0;
    forn(i, left.size()) res = max(res, left[i]);
    forn(i, right.size()) res = max(res, right[i]);

    for(long long e: left){
        auto it = upper_bound(all(right), M - e - 1);
        if(it == right.begin()) continue;
        it--;
        res = max(res, e + (*it));
    }

    cout << res << endl;
}