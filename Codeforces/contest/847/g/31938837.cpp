#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long int ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	int n;
	int res[1111];
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>res[i];
	for(int i=0;i<7;i++){
		int r=0;
		for(int j=0;j<n;j++){
			r+=res[j]%10;
			res[j]/=10;
		}
		ans=max(ans,r);
	}
	cout<<ans<<endl;
}
