#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vec;
typedef pair<ll,ll> pll;
int main(){
	int n,m;
	cin>>n>>m;
	int now=m;
	int data;
	int cnt=0;
	bool ok=false;
	int anscnt,ans;
	anscnt=ans=0;
	for(int i=0;i<n;i++){
		cin>>data;
		//cout<<now<<" "<<data<<endl; 
		now-=data;
		if(now<=0){
			cnt=1;
			now=m-data;
			vec.push_back(data);
		}else{
			cnt++;
			if(cnt==2){
				vec.push_back(now+data);
				anscnt++;
				ans+=now;
				cnt=1;
				now=m-now-data;
			}else{
				vec.push_back(data);
			}
		}
	}
	cout<<ans<<endl;
	cout<<vec[0];
	for(int i=1;i<n;i++){
		cout<<" "<<vec[i];
	} 
	cout<<endl;
}