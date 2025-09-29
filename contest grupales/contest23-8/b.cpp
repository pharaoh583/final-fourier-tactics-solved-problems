#include<iostream>
#include<vector>
#include<cassert>
#include<tuple>
#include<iomanip>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long
#define ii pair<ll, ll>
#define pb push_back
#define el "\n"
using namespace std;

int main(){
    int n, k;
    double  s, d;
    cout<<setprecision(6)<<fixed;
    vector< pair < double, double> > v;
    cin>>n>>k;
    cin>>s>>d;
    v.pb(make_pair(s,d));
    double men = d, may = d;
    forn(i, n - 1){
        cin>>s>>d;
        v.pb(make_pair(s,d));
        men = min(men, d);
        may = max(may, d);
    }
    double t, aux;
    double sol = 0.000000;
    aux = v[0].first - v[1].first;
    if(aux != 0){
        t = (v[1].second - v[0].second) / (v[0].first - v[1].first);
        if(t < 0 || t > k || may - men == 0){
            cout<<setprecision(6)<<fixed<< (double)may - men<<el;
        }
        else{
            double p;
            p = v[0].first * t + v[0].second;
            bool flag = true;
            for(int i = 1; i < n; i++){
                if(p != v[i].first * t + v[i].second){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<setprecision(6)<<fixed<<(double) sol<<el;
            }
            else{
                cout<<setprecision(6)<<fixed<<(double) may - men<<el;
            }
        }
    }
    else{
        if(v[1].second  == v[0].second){
            cout<<setprecision(6)<<fixed<<(double) sol<<el;
        }
        else{
            cout<<setprecision(6)<<fixed<<(double) may - men<< el;
        }
    }


    return 0;
}