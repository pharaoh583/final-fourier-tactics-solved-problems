#include<iostream>
#include<stack>
#include<map>
#include<vector>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define vi vector<int>
#define pb push_back
#define mp make_pair
using namespace std;

vector<string> split(string s, char sp) {
    s += sp;
    vector<string> res;
    string aux = "";
    forn(i, s.size()) {
        if(s[i] == sp) {
            if(aux.size() != 0) res.pb(aux);
            aux = "";
        }
        else {
            aux += s[i];
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    map < string, int> m;
    vector<pair< string, string> > names;
    string s; getline(cin, s);
    forn(i, n){
        getline(cin, s);
        vector<string> vs = split (s, ' ');
        vs[0] = split(vs[0], ',')[0];
        //cout<<"hola"<<vs[0]<<vs[3]<<endl;
        // forn(j, vs.size()){
        //     cout<<vs[j]<<" ";
        // }
        names.pb(mp(vs[0], vs[3])); 
        m[vs[0]] = 0;
        m[vs[3]] = 0;
    }
    forn(i, n){
        if(names[i].first == names[i].second) continue;
        m[names[i].first]++;
    }
    int c = 0;
    for(auto k: m){
        if(k.second == 0) c++;
    }
    if(c > 1){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<"possible"<<endl;
    }
}