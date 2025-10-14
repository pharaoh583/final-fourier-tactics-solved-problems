#include<iostream>
#include<stack>
#include<map>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;

int main() {
    int n; cin >> n;
    int length = 0;
    string res = "";
    string input = ".";
    forn(i, n){
        char c; cin >> c;
        input += c;
    }
    input+='.';

    // cout << endl;
    // cout << endl;
    // cout << input << endl;
    stack<char> in_line;
    forn(i, n+2){
        char c = input[i];
        bool f = false;

        if(in_line.empty()){
            in_line.push(c);
            continue;
        }

        if(c == '.'){
            if(in_line.top() == '.'){
                in_line.pop();
                f = true;
            }

            if(in_line.empty()){
                if(length == 2){
                    res += 'w';
                }
                else{
                    res += 'v';
                }
                length = 0;
                in_line.push('.');
            }
        }
        else if(c == '/'){
            if(in_line.top() == '\\'){
                in_line.pop();
                length++;
                f = true;
            }
        }

        if(f == false) in_line.push(c);
    }

    forn(i, n){
        char c; cin >> c;
    }

    cout << res<<endl;
}