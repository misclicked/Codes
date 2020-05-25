#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,char> pic;
typedef vector<pic> vpic;
typedef vector<pll> vll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,m;
	cin>>n>>m;
	if(n==m){
		cout<<n<<endl;
		return 0;
	}
	vii vec;
	vec.push_back(pii(floor(m/2) - ceil(m/2),2));
	vec.push_back(pii(floor(m/3) - ceil(m/2),3));
	vec.push_back(pii(floor(m/5) - ceil(m/2),5));
	vec.push_back(pii(floor(m/7) - ceil(m/2),7));
	sort(vec.begin(),vec.end(),greater<pii>());
	cout<<vec[0].second<<endl;
}


