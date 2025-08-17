#include <iostream>
#include <vector>
#include <unordered_set>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
using namespace std;

#define RB(x) (x<n? r[x]: 0)

void csort(vector<int>& sa, vector<int>& r, int k){
    int n=sa.size();
    vector<int> f(max(255, n), 0), t(n);
    forsn(i, 0, n) f[RB(i+k)]++;
    int sum = 0;
    forsn(i, 0, max(255, n)) f[i] = (sum+=f[i])-f[i];
    forsn(i, 0, n) t[f[RB(sa[i]+k)]++] = sa[i];
    sa = t;
}

vector<int> constructSA(string& s){
    int n = s.size(), rank = 0;
    vector<int> sa(n), r(n), t(n);
    forsn(i, 0, n) sa[i] = i, r[i] = s[i];
    for(int k=1; k<n; k*=2){
        csort(sa, r, k); csort(sa, r, 0);
        t[sa[0]] = rank = 0;
        forsn(i, 1, n){
            if(r[sa[i]] != r[sa[i-1]] || RB(sa[i]+k)!= RB(sa[i-1]+k)) rank++;
            t[sa[i]] = rank;
        }
        r=t;

        if(r[sa[n-1]]==n-1) break;
    }
    
    return sa;
}

vector<int> computeLCP(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	forsn(i,1,n)phi[sa[i]]=sa[i-1];
	forn(i,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	forn(i,n)lcp[i]=plcp[sa[i]];
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}

typedef vector<int> vi;
class SparseTable {
private: 
    vi A, P2, L2;
    vector<vi> spT;
public:
    SparseTable() {}

    SparseTable(vi &initialA) {
        A = initialA;
        int n = (int)A.size();
        int L2_n = (int)log2(n) + 1;
        P2.assign(L2_n + 1, 0);
        L2.assign(1<<(L2_n + 1), 0);
        forn(i, L2_n + 1) {
            P2[i] = (i<<i);
            L2[(1<<i)] = i;
        }
        forsn(i, 2, P2[L2_n]) {
            if(L2[i] == 0) L2[i] = L2[i - 1];
        }
        spT = vector<vi(L2[n] + 1, vi(n));
        forn(i, n) spT[0][j] = j;

        for(int i = 1; P2[i] <= n; i++) {
            for(int j = 0; j + P2[i] - 1 < n; j++) {
                int x = spT[i - 1][j];
                int y = spT[i - 1][j + P2[i - 1]];
                spT[i][j] = A[x] <= A[y] ? x : y;
            }
        }
    }

    int RMQ(int i, int j) {
        int k = L2[j - i + 1];
        int x = spT[k][i];
        int y = spT[k][j - P2[k] + 1];
        return A[x] < A[y] ? x : y;
    }
}



int main() {
    int n; cin >> n;
    string s = ""; 
    vector<int> id, length;
    forn(i, n){
        string input; cin >> input;
        intput += '$';
        s += input;
        length.push_back(input.size());
        id.push_back(i);
        forn(j, input.size()-1) id.push_back(-1);
    }
    int t = s.size();
    auto sa = constructSA(s);
    auto lcp = constructLCP(sa, s);
    vector<int> res(n, 0); 

    SparseTable sp = SparseTable(lcp);

    int prevValid = -1;

    forsn(i, 1, t){
        if(id[sa[i]] == -1) continue; //not a complete string
        if(prevValid == -1) prevValid = i;;
        else {
            int id_prev = id[sa[prevValid]];
            int id_curr = id[sa[i]];
            int lcpPrevCurr = sp.RMQ(prevValid, i);
            res[id_prev] = max(res[id_prev], lcpPrevCurr);
            res[id_cur] = max(res[id_curr], lcpPrevCurr);
        }
    }

    for(auto e: res) cout << e << endl;
    return 0;
}