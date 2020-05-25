#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int input[150005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	ll n,m,here;
	cin>>n>>m;
	ll ans=LLONG_MAX;
	ll now=0;
	for(int i=0;i<n;i++){
		cin>>input[i];
		now+=input[i];
		if(i>=(m-1)){
			if(ans>now){
				ans=min(ans,now);
				here=(i+1)-m+1;
			}
			now-=input[i-m+1];
		}
	}
	cout<<here<<endl;
}