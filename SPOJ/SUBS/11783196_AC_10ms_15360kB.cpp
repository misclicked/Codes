#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool can(string& a,string &b, ll M){
	if(M==0)return true;
	ll cnt=0;
	ll k=0,i,j;
	for(i=0;i<a.length()&&k<b.length();i++){
		for(int j=0;j<M&&k<b.length();j++){
			while(k<b.length()&&b[k]!=a[i])k++;
			if(b[k]!=a[i])return false;
			k++;
			cnt++;
		}
	}
	return cnt==a.length()*M;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int T;
	cin>>T;
	string a,b;
	while(T--){
		a=b="";
		cin>>a>>b;
		ll ans=0;
		ll l=0,r=ceil(b.length()/a.length()),mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(can(a,b,mid)){
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
}
