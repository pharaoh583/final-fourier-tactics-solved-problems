#include <bitset>
#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

const int MAXI = 201;
bitset<201> table[MAXI];
int r, c;


int main() {
    cin >> r >> c;
    forn(i, r){
        string s; cin >> s;
        table[i] = bitset<201>(s);
    }

    int res = 0;
    forn(i, r){
        bitset<201> acc = table[i];
        forsn(j, i, r){
            acc &= table[j];
            int len = 0;
            forn(k, c){
                if(acc[k]) len++;
                else{
                    res = max(res, (j-i+1)*len);
                    len = 0;
                }
            }
            res = max(res, (j-i+1)*len);
        }
    }

    cout << res << endl;
}