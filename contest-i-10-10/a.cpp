#include <bits/stdc++.h> 

#define forn(i, n) for(int i = 0 ; i < n; ++ i)
#define forsn(i, k, n)  for(int i = k ; i < n; ++ i)
using namespace std;

int main(){
    int n, q;
    cin>> n>> q;
    vector < vector < int > > v (n, vector < int > (n) );
    char aux;
    forn(i, n){
        forn(j, n){
            cin>>aux;
            //cout<<aux<< ' ';
            if(aux == '.') v[i][j] = 0;
            else v[i][j] = 1;
        }
    }

    forn(i, n){
        forsn(j,1, n){
           v[i][j] += v[i][j-1];
        }
    }
    int y1, x1, y2, x2;
    int sol;

    while(q -- ){
        cin>>y1 >> x1>> y2 >> x2;
        sol = 0;
        forsn(i,y1,y2+1){
            
            if(x1 >= 2){
                sol += v[i - 1][x2 - 1] - v[i - 1][x1 - 2];
            }
            else{
                sol += v[i - 1][x2 - 1];
            }
        }
        cout<<sol<< endl;
    }







}
