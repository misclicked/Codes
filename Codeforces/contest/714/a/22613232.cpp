#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	ll l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	ll ans=0;
	if(r1>=l2&&r1<=r2&&l2>=l1&&l2<=r1){
		ans+=(r1-l2+1);
		if(k>=l2&&k<=r1)
			ans--;
	}
	else if(r1>=r2&&l2>=l1){
		ans+=(r2-l2+1);
		if(k>=l2&&k<=r2)
			ans--;
	}
	else if(r1>=r2&&l2<=l1&&l1<=r2){
		ans+=(r2-l1+1);
		if(k>=l1&&k<=r2)
			ans--;
	}
	else if(r1<=r2&&l2<=l1){
		ans+=(r1-l1+1);
		if(k>=l1&&k<=r1)
			ans--;
	}
	cout<<ans<<endl;
	return 0;
}