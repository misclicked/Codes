#include<bits/stdc++.h>
#define RSZ(X,N) (X).resize((N))
#define ALL(X) (X).begin(), (X).end()
#define SZ(X) ((int)(X).size())
#define REP(I,N) for(int I = 0; I < (N); I++)
#define REPP(I,A,B) for(int I = (A); I < (B); I++)
#define FOR(I,N) for(int I = 0; I <= (N); I++)
#define FORR(I,A,B) for(int I = (A); I <= (B); I++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef pair<ll,pll> plll;
typedef vector<ll> vl;
template<class T> T _MIN(){return numeric_limits<T>::min();};
template<class T> T _MAX(){return numeric_limits<T>::max();};
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%I64d", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%I64d", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
template<class T> void _W(const deque<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
template<class T, class... U> void DEBUG(const T &head, const U &... tail) {
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
set<char> se;
int main(){
	int n;
	R(n);
	char c;string s;int ans=0;
				vector<char> tmp;
	FORR(i,'a','z')se.insert(i);
	REP(i,n){
		R(c);
		R(s);
		switch(c){
			case '!':{
				if(se.size()==1){
					ans++;
					break;
				}
				tmp.clear();
				for(auto it:se){
					bool flag=false;
					REP(i,SZ(s)){
						if(s[i]==it)flag=true;
					}
					if(!flag)tmp.PB(it);
				}
				for(auto it:tmp)
					se.erase(it);
				//cout<<se.size()<<endl;
				break;
			}
			case '.':{
				for(auto it:s){
					se.erase(it);
				}
				//cout<<se.size()<<endl;
				break;
			}
			case '?':{
				if(i==n-1)break;
				if(se.size()==1){
					if(s[0]!=*se.begin())
						ans++;
				}else{
					se.erase(s[0]);
				}
				break;
			}
		}
	}
	cout<<ans<<endl;
}
