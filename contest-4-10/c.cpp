#include<iostream>
#include<vector>
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

int limit;
int s;
int cont = 0;
void generate(int idx, int prev) {
    cout<<"generate("<<idx<<","<<prev<<")"<<endl;
    if(idx == s) {
        cont++; return;
    }
    forsn(i, prev, limit + 1) {
        generate(idx + 1, i);
    }
}
int main() {
    int n; cin>>n;
    s = limit = n;
    generate(0, 1);
    cout<<2 * cont - n<<endl;
}