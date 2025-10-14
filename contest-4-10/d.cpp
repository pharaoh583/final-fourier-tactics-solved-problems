#include<iostream>
#include<vector>
#include<queue>
#include<functional>

#define FastIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define vi vector<int>
#define ii pair<int, int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
#define el '\n'

using namespace std;

const int MAXI = 200000 + 1;

int n, k, q;
int dp[MAXI] = {};
ii rangess[MAXI] = {};
ii queries[MAXI] = {};
// vector <string> patterns;
int main() {
    FastIO;
    cin >> n >> k >> q;
    forn(i, n){
        int l, r; cin >> l >> r;
        rangess[i] = {l, r};
    }
    forn(i, q){
        int a, b; cin >> a >> b;
        queries[i] = {a, b};
    }

    sort(rangess, rangess + n); int j = 0;
    priority_queue<int, vector<int>,  greater<int>> in_line;
    forn(i, MAXI){
        while(!in_line.empty() && in_line.top() < i) in_line.pop();
        while(j < n && rangess[j].first <= i){
            in_line.push(rangess[j].second); j++;
        } 
        if(in_line.size() >= k) dp[i] = 1;
    }

    // forn(i, n){
    //     cout << dp[i] << " ";
    // } cout << el;

    forsn(i, 1, MAXI) dp[i] += dp[i-1];

    forn(i, q){
        int a = queries[i].first;
        int b = queries[i].second;
        int res = dp[b];
        if(a>0) res -= dp[a-1];
        cout << res << el;
    }
}