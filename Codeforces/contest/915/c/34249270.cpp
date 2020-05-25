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
int mape[11];
string a,b;
void dfs(int n,ll ans,bool flag){
	if(n==SZ(a)){
		cout<<ans<<endl;
		exit(0);
	}
	int now=0;
	if(flag)now=9;
	else now=b[n]-'0';
	for(int i=now;i>=0;i--){
		if(mape[i]){
			if(now==i){
				mape[i]--;
				dfs(n+1,ans*10+i,flag);
				mape[i]++;
			}else{
				mape[i]--;
				dfs(n+1,ans*10+i,true);
				mape[i]++;
			}
		}
	}
}
int main(){
	cin>>a>>b;
	MS0(mape);
	REP(i,SZ(a))mape[a[i]-'0']++;
	if(SZ(b)>SZ(a)){
		dfs(0,0,true);
	}else{
		dfs(0,0,false);
	}
}
