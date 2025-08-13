#include<iostream>
#include<vector>
#include<algorithm>
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define ii pair<int, int>
using namespace std;

#define RB(x) (x < n ? r[x] : 0)

void csort(vector<int>& sa, vector<int>& r, int k) {
    int n = sa.size();
    vector<int> f(max(255, n), 0), t(n);
    forn(i, n) f[RB(i + k)]++;
    int sum  = 0;
    forn(i, max(255, n)) f[i] = (sum += f[i]) - f[i];
    forn(i, n) t[f[RB(sa[i] + k)]++] = sa[i];
    sa = t;
}

vector<int> constructSA(string& s) {
    int n = s.size(), rank;
    vector<int> sa(n), r(n), t(n);
    forn(i, n) sa[i] = i, r[i] = s[i];
    for(int k = 1; k < n; k *= 2) {
        csort(sa, r, k); csort(sa, r, 0);
        t[sa[0]] = rank = 0;
        for(int i = 1; i < n; i++) {
            if(r[sa[i]] != r[sa[i - 1]] or RB(sa[i] + k) != RB(sa[i - 1] + k)) rank++;
            t[sa[i]] = rank;
        }
        r = t;
        if (r[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

int findRange(string& s1, string& s2, vector<int>& sa) {
    if (s2.size() < s1.size()) {
        return 0;
    }
    int result_start = 0, result_end = s2.size() - 1;
    for (int i = 0; i < s1.size(); i++) {
        int start = lower_bound(sa.begin() + result_start, sa.begin() + result_end + 1, s1[i], [&](int idx, char b) {
            return idx + i >= s2.size() || s2[idx + i] < b;
        }) - sa.begin();
        if (start > result_end || (s2[sa[start] + i]) != s1[i]) {
            return 0;
        }
        int end = upper_bound(sa.begin() + result_start, sa.begin() + result_end + 1, s1[i], [&](char b, int idx) {
            return idx + i < s2.size() && s2[idx + i] > b;
        }) - sa.begin() - 1;
        result_start = start;
        result_end = end;
    }
    return result_end - result_start + 1;
}

int main() {
    string s; cin>>s;
    s += '$';
    vector<int> sa = constructSA(s);

    int n; cin>>n;
    while(n--) {
        string p; cin>>p;
        cout<<findRange(p, s, sa)<<endl;
    }
}