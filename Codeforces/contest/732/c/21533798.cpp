#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vec;
typedef pair<ll,ll> pll;
ll come[][3]={
	{0,0,0},{0,-1,-1},
	{0,0,-1}
};
ll out[][3]={
	{0,0,0},{-1,-1,0},
	{-1,0,0}
};
int main(){
	ll input[3];
	ll ans=LLONG_MAX;
	for(int i=0;i<3;i++){
		cin>>input[i];
	}
	ll tmp[3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				tmp[k]=input[k]+come[i][k];
				tmp[k]+=out[j][k];
			}
			sort(tmp,tmp+3);
			ans=min(ans,tmp[2]-tmp[0]+tmp[2]-tmp[1]);
		}
	}
	cout<<ans<<endl;
}