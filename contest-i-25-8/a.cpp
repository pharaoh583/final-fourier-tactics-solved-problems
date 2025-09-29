#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
    vector<int> v;
    for(int i = 0; i < 3; i++) {
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    if(v[0] + v[1] > v[2]) {
        cout<<"OK"<<endl;
    } else {
        cout<<"Wrong!!"<<endl;
    }
}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}