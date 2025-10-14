#include<iostream>
#include<vector>
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

vector < string > words;
void generate(int idx, string& p, string currWord) {
    if(idx == p.size()) {
        cout<<currWord<<endl;
        return ;
    }
    if(p[idx] == '#'){
        forn(i, words.size()){
            generate( idx + 1 ,p , currWord  + words[i]);
        }
    }
    else{
        forn(i, 10){
            generate( idx + 1 ,p , currWord  + char(i + '0'));
        }
    }
    
}
// vector <string> patterns;
int main() {
    int n, p;
    string s;
    while(cin>>n){
        cout<<"--"<<endl;
        words.clear();
        // patterns.clear();
        forn(i,n){
            cin>>s;
            words.pb(s);
        }
        cin>>p;
        forn(i, p){
            cin>>s;
            generate(0, s, "");
        }
    }
}