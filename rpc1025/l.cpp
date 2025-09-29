#include <bitset>
#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;


int main() {
    int t; cin >> t;

    int res = 2000;
    for(int i = 0; i<= t; i++){
        int work = t - i;
        if(work > 600) continue;   
        if(work > 540) {
            if(i >= 45){
                res = min(res, i);
            } 
        }
        else if(work > 360){
            if(i >= 30){
                res = min(res, i);
            }
        }
        else{
            res = min(res, i);
        }
    }

    cout << res << endl;
}