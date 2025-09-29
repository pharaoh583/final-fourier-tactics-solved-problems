#include<iostream>
#include<algorithm>
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
    string a; cin>>a;
    sort(all(a)); //O(nlogn)

    vector<string> v;

    do { 
        v.push_back(a); //O(1)
    } while(next_permutation(all(a))); //O(n! * n)

    cout<<v.size()<<endl;
    for(auto x : v) cout<<x<<endl; //O(n!)
}